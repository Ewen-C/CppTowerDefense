// Fill out your copyright notice in the Description page of Project Settings.


#include "TDEnemy.h"

#include "CppTowerDefense/TDPlayerState.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATDEnemy::ATDEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>("EnemyMesh");
    RootComponent = EnemyMesh;
}

void ATDEnemy::InitializeSpline(USplineComponent* PathToFollow)
{
	SplineToFollow = PathToFollow;
	SplineLength = PathToFollow->GetSplineLength();
	DistanceAlongSpline = 0.0f;
}

void ATDEnemy::InitializeStats(const FTDEnemyStats* Stats)
{
	EnemyStats = Stats;
	MoveSpeed = EnemyStats->MovementSpeed;

	if(!Stats->EnemyMesh.IsNull()) 
	{
		EnemyMesh->SetStaticMesh(Stats->EnemyMesh.Get());

		if(!Stats->EnemyMaterial.IsNull()) EnemyMesh->SetMaterial(0, Stats->EnemyMaterial.LoadSynchronous());
		else UE_LOG(LogTemp, Error, TEXT("No Material defined for Enemy %p !"), this->GetClass());
	}
	else UE_LOG(LogTemp, Error, TEXT("No Mesh defined for Enemy %p !"), this->GetClass());
}

// Called every frame
void ATDEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveAlongSpline(DeltaTime);
}

void ATDEnemy::MoveAlongSpline(float DeltaTime)
{
	if(SplineToFollow == nullptr) return;
	
	DistanceAlongSpline += MoveSpeed * DeltaTime;

	// Check if end reached
	if(DistanceAlongSpline >= SplineLength) Die();
	
    // Update position and rotation
    FVector NewLocation = SplineToFollow->GetLocationAtDistanceAlongSpline(
        DistanceAlongSpline, 
        ESplineCoordinateSpace::World
    );
    
    FRotator NewRotation = SplineToFollow->GetRotationAtDistanceAlongSpline(
        DistanceAlongSpline, 
        ESplineCoordinateSpace::World
    );

    SetActorLocationAndRotation(NewLocation, NewRotation);
}

void ATDEnemy::Die()
{	
	UE_LOG(LogTemp, Log, TEXT("Enemy died !"));

	AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), ATDPlayerState::StaticClass());
	if(FoundActor == nullptr) UE_LOG(LogTemp, Fatal, TEXT("Can't get ATDPlayerState in Enemy !"));

	ATDPlayerState* TD_PS = Cast<ATDPlayerState>(FoundActor);
	TD_PS->AddMoney(EnemyStats->MoneyReward);

	OnEnemyDeath.Broadcast();
	Destroy();
}

