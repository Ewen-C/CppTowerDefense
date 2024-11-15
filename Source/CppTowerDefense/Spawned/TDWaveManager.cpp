// Fill out your copyright notice in the Description page of Project Settings.


#include "TDWaveManager.h"

#include "Engine/SplineMeshActor.h"


// Sets default values
ATDWaveManager::ATDWaveManager()
{
    PrimaryActorTick.bCanEverTick = false;
	
    // Dummy root component
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

// Called when the game starts or when spawned
void ATDWaveManager::BeginPlay()
{
	Super::BeginPlay();

	AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), ATDWaveTarget::StaticClass());
	if(FoundActor == nullptr) UE_LOG(LogTemp, Fatal, TEXT("No AWaveTarget in scene !"));
	
	WaveTarget = Cast<ATDWaveTarget>(FoundActor);
	if(WaveTarget == nullptr) UE_LOG(LogTemp, Fatal, TEXT("Cast to WaveTarget failed !"));
		
}

void ATDWaveManager::InitDT(UDataTable* Gm_DTWaveComposition, UDataTable* Gm_DTEnemyStats)
{
	DTWaveComposition = Gm_DTWaveComposition;
	DTEnemyStats = Gm_DTEnemyStats;

	WaveNames = DTWaveComposition->GetRowNames();
}

void ATDWaveManager::StartWave()
{
	// Get current data row

	const FTDWaveComposition* CurrentWaveComp =
		DTWaveComposition->FindRow<FTDWaveComposition>(WaveNames[CurrentWaveIndex], TEXT(""));
	
    if (CurrentWaveComp == nullptr || CurrentWaveComp == NULL)
    {
	    UE_LOG(LogTemp, Error, TEXT("No more wave data !"));
    	return;
    }

	// Create array from data map

	SpawnEnemyOrder.Empty();
	CurrentEnemyIndex = 0;

	for(const auto& Pair : CurrentWaveComp->EnemyComposition)
		for (int32 i = 0; i < Pair.Value; i++) SpawnEnemyOrder.Add(Pair.Key); // Add all enemies with their type

	if(SpawnEnemyOrder.Num() == 0)
	{
		UE_LOG(LogTemp, Error, TEXT("Empty wave !"));
		return;
	}

	CurrentEnemyCount = SpawnEnemyOrder.Num();
	LastEnemyIndex = SpawnEnemyOrder.Num() - 1;

	if(CurrentWaveComp->SpawnTypesRandomly)
	{
		for (int32 i = 0; i < LastEnemyIndex - 1; i++)
		{
			const int32 RandIndex = FMath::RandRange(i+1, LastEnemyIndex);
			SpawnEnemyOrder.Swap(RandIndex, LastEnemyIndex);
		}
	}
	
	CurrentWaveIndex++;

	// Spawn first enemy (to not wait for first timer)

	SpawnNextEnemy();
	if(CurrentEnemyIndex == LastEnemyIndex + 1) return;

	// Spawn enemies continuously
    
    GetWorldTimerManager().SetTimer(
        SpawnTimerHandle,
        this,
        &ATDWaveManager::SpawnNextEnemy,
        CurrentWaveComp->SpawnInterval,
        true
    );
}

void ATDWaveManager::SpawnNextEnemy()
{
	// UE_LOG(LogTemp, Log, TEXT("CurrentEnemyIndex : %i"), CurrentEnemyIndex);
	// UE_LOG(LogTemp, Log, TEXT("LastEnemyIndex : %i"), LastEnemyIndex);
	
	// Get start of spline path

	FVector SpawnPoint = WaveTarget->GetPathStartLocation();

	// Spawn enemy at the start of the spline path

    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this; // Set the ownership to this actor
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    // Spawn the enemy
    ATDEnemy* NewEnemy = GetWorld()->SpawnActor<ATDEnemy>(
        ATDEnemy::StaticClass(),
        SpawnPoint,
        FRotator::ZeroRotator,
        SpawnParams
    );

	if(NewEnemy == nullptr) UE_LOG(LogTemp, Fatal, TEXT("Enemy spawn failed !"));

	// Load the spline & stats of the enemy
	
	FString StringEnemyType = UEnum::GetValueAsString(SpawnEnemyOrder[CurrentEnemyIndex]); // Enum with ::
	FString SplitEnemyType;
	StringEnemyType.Split(TEXT("::"), nullptr, &SplitEnemyType); // Right part of enum after ::

	UE_LOG(LogTemp, Log, TEXT("Spawned enemy %s"), *SplitEnemyType);
        
    const FTDEnemyStats* CurrentEnemyStats = DTEnemyStats->FindRow<FTDEnemyStats>(
        FName(*SplitEnemyType), 
        TEXT("")
    );

	if(CurrentEnemyStats == nullptr) UE_LOG(LogTemp, Fatal, TEXT("Enemy get stats failed !"));
	
	NewEnemy->InitializeStats(CurrentEnemyStats);
	NewEnemy->InitializeSpline(WaveTarget->GetPath());
	NewEnemy->OnEnemyDeath.AddUObject(this, &ATDWaveManager::EnemyDied); // Bind event

	UE_LOG(LogTemp, Log, TEXT("Spawned enemy %i of %i from wave %i"), CurrentEnemyIndex+1, CurrentEnemyCount, CurrentWaveIndex);

	if(CurrentEnemyIndex == LastEnemyIndex && SpawnTimerHandle.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
	}
	
	else CurrentEnemyIndex++;
}

void ATDWaveManager::EnemyDied()
{
	CurrentEnemyCount--;
	UE_LOG(LogTemp, Log, TEXT("Remaining enemies : %i"), CurrentEnemyCount);
	if(CurrentEnemyCount == 0) OnAllEnemiesDied.Broadcast();
}
