// Fill out your copyright notice in the Description page of Project Settings.


#include "TDWaveManager.h"

// Sets default values
ATDWaveManager::ATDWaveManager()
{
    PrimaryActorTick.bCanEverTick = false;
    
    PathSpline = CreateDefaultSubobject<USplineComponent>("PathSpline");
    RootComponent = PathSpline;
}

// Called when the game starts or when spawned
void ATDWaveManager::BeginPlay()
{
	Super::BeginPlay();

	// Get spline paths
	
}

void ATDWaveManager::InitDT(UDataTable* Gm_DTWaveComposition, UDataTable* Gm_DTEnemyStats)
{
	DTWaveComposition = Gm_DTWaveComposition;
	DTEnemyStats = Gm_DTEnemyStats;

	WaveNames = DTWaveComposition->GetRowNames();
}

// Called every frame
void ATDWaveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATDWaveManager::StartWave()
{
	// Get current data row

	const FTDWaveComposition* CurrentWaveComp =
		DTWaveComposition->FindRow<FTDWaveComposition>(WaveNames[CurrentWaveIndex], TEXT(""));
	
    if (CurrentWaveComp == nullptr || CurrentWaveComp == NULL) UE_LOG(LogTemp, Error, TEXT("No more wave data ! "));

	// Create array from data map

	SpawnEnemyOrder.Empty();

	for(const auto& Pair : CurrentWaveComp->EnemyComposition)
		for (int32 i = 0; i < Pair.Value; i++) SpawnEnemyOrder.Add(Pair.Key); // Add all enemies with their type

	LastEnemyIndex = SpawnEnemyOrder.Num() - 1;

	if(CurrentWaveComp->SpawnTypesRandomly)
	{
		for (int32 i = 0; i < LastEnemyIndex - 1; i++)
		{
			const int32 RandIndex = FMath::RandRange(i+1, LastEnemyIndex);
			SpawnEnemyOrder.Swap(i, LastEnemyIndex);
		}
	}

	// Spawn enemies continuously
	
	CurrentWaveIndex++;
    
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
	// Get start of spline path

	// Spawn enemy at the start of the spline path

	// EEnemyType CurrentEnemyType = SpawnEnemyOrder[CurrentEnemyIndex];

	// Load the stats and send them in the enemy constructor 

	UE_LOG(LogTemp, Log, TEXT("Spawned enemy %i of %i from wave %i"), CurrentEnemyIndex, LastEnemyIndex, CurrentWaveIndex);

	if(CurrentEnemyIndex == LastEnemyIndex)
	{
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimerHandle);
		OnWaveFinished.Broadcast();
	}
	else CurrentEnemyIndex++;
}

