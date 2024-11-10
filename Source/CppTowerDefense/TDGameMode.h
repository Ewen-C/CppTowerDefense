// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TDGameMode.generated.h"

UCLASS()
class CPPTOWERDEFENSE_API ATDGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATDGameMode();

	// Game Flow

	UFUNCTION()
	void Init();
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Loop")
    int32 StartingMoney = 8;

	UFUNCTION(BlueprintCallable, Category = "Game Loop")
	void StartWave();

	UFUNCTION(BlueprintCallable, Category = "Game Loop")
	void EndWave();

	UFUNCTION(BlueprintCallable, Category = "Game Loop")
	void OnLose();

protected:
	virtual void BeginPlay() override;

	// Game state

	bool WaveStarted = false;
	int32 CurrentWave = 0;
	int32 CurrentEnemyCount = 0;
	
};
