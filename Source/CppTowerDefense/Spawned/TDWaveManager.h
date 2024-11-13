// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CppTowerDefense/TDDataStructs.h"
#include "Enemy.h"
#include "Components/SplineComponent.h"
#include "TDWaveManager.generated.h"

// Delegates - must be before the UCLASS ; MULTICAST -> Exposed to BPs
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWaveFinished);

UCLASS()
class CPPTOWERDEFENSE_API ATDWaveManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATDWaveManager();

	void InitDT(UDataTable* Gm_DTWaveComposition, UDataTable* Gm_DTEnemyStats);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void StartWave();

	// Events
	FOnWaveFinished OnWaveFinished;

protected:
	// Get DataTables from GameMode on spawn	
    UPROPERTY()
    UDataTable* DTWaveComposition;
	
    UPROPERTY()
    UDataTable* DTEnemyStats;
	
    UPROPERTY(EditInstanceOnly, Category = "Wave Setup")
    class USplineComponent* PathSpline;

	UPROPERTY() 
    TMap<EEnemyType, int32> SpawnedEnemiesCount;

    UFUNCTION()
    void SpawnNextEnemy();
	
	int32 CurrentWaveIndex = 0;
	float CurrentSpawnInterval = 0;
	int32 CurrentEnemyIndex = 0;
	int32 LastEnemyIndex = 0;

	TArray<FName> WaveNames; // FNames of the DataTable Wave Composition
    FTimerHandle SpawnTimerHandle; // Timer that spawns enemies
	TArray<EEnemyType> SpawnEnemyOrder; // Array listing all enemies in current wave

};
