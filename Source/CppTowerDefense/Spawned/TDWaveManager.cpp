// Fill out your copyright notice in the Description page of Project Settings.


#include "TDWaveManager.h"
#include "Components/SplineComponent.h"
#include "Enemy.h"

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
	
	if (DataTableEnemyStats == nullptr)
		UE_LOG(LogTemp, Error, TEXT("No DataTableEnemyStats loaded !"));
}

// Called every frame
void ATDWaveManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATDWaveManager::StartWave()
{
    // if (CurrentWaveIndex >= Waves.Num())
    // {
    //     // All waves completed
    //     return;
    // }

	// Get Wave data
	// CurrentEnemyCount =

	// If wave data has simultaneous spawn

	// Start to spawn enemies
	// DataTableEnemyStats->FindRow<FEnemyStats>(EnemyType, TEXT(""));
}

void ATDWaveManager::SpawnNextEnemy()
{
	
}

