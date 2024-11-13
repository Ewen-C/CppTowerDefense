// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CppTowerDefense/TDDataStructs.h"
#include "GameFramework/Actor.h"
#include "TDWaveManager.generated.h"

UCLASS()
class CPPTOWERDEFENSE_API ATDWaveManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATDWaveManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void StartWave();

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Loop")
    UDataTable* DataTableEnemyStats;
	
    UPROPERTY(EditInstanceOnly, Category = "Wave Setup")
    class USplineComponent* PathSpline;

	UPROPERTY() 
    TMap<EEnemyType, int32> SpawnedEnemiesCount;

    UFUNCTION()
    void SpawnNextEnemy();
	
	int32 CurrentWaveIndex = 0;

};
