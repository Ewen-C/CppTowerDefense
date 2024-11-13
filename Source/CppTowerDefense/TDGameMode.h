// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Spawned/TDWaveManager.h"
#include "TDGameMode.generated.h"

// Delegates - must be before the UCLASS ; MULTICAST -> Exposed to BPs
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWaveFinished);

UCLASS()
class CPPTOWERDEFENSE_API ATDGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATDGameMode();
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Loop")
    int32 StartingMoney = 8;

	UFUNCTION(BlueprintCallable, Category = "Game Loop")
	void OnLose();

	UFUNCTION(BlueprintCallable, Category = "Game Loop")
	void DecrementEnemyCount();

	UFUNCTION(BlueprintCallable, Category = "Game Loop")
	void StartWave();

	UFUNCTION(BlueprintCallable, Category = "Game Loop")
	void EndWave();

	// Events
	FOnWaveFinished OnWaveFinished;

protected:
	// Game state
	bool WaveOngoing = false;
	
    UPROPERTY()
    ATDWaveManager* WaveManager;
	
};
