// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "PS_TD.h"
#include "PC_TD.h"

#include "GM_TD.generated.h"

/**
 * 
 */
UCLASS()
class CPPTOWERDEFENSE_API AGM_TD : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGM_TD();

	// Game Flow

	UFUNCTION(BlueprintCallable, Category = "System")
	void Init();

	UFUNCTION(BlueprintCallable, Category = "System")
	void OnLose();

	UFUNCTION(BlueprintCallable, Category = "Game Loop")
	void StartWave();

	UFUNCTION(BlueprintCallable, Category = "Game Loop")
	void EndWave();

protected:
	virtual void BeginPlay() override;

	// Game state

	bool WaveStarted = false;
	int32 CurrentWave = 0;
	int32 CurrentEnemyCount = 0;
	
	
};
