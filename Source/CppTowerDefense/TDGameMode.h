// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Spawned/TDWaveManager.h"
#include "TDGameMode.generated.h"

UCLASS()
class CPPTOWERDEFENSE_API ATDGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATDGameMode();
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metrics")
    int32 StartingMoney = 8;

	UFUNCTION(BlueprintCallable, Category = "Game Loop") // Called in HUD
	void StartWave();

	UFUNCTION()
	void EndWave();

	UFUNCTION()
	void OnLose();

protected:
	virtual void BeginPlay() override;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metrics")
    UDataTable* DTWaveComposition;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metrics")
    UDataTable* DTEnemyStats;
	
    UPROPERTY()
    ATDWaveManager* WaveManager;
	
};
