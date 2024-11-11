// Fill out your copyright notice in the Description page of Project Settings.


#include "TDGameMode.h"
#include "TDPlayerState.h"
#include "TDPlayerController.h"

ATDGameMode::ATDGameMode()
{
	// Setup GameMode

	PlayerStateClass = ATDPlayerState::StaticClass();
	PlayerControllerClass = ATDPlayerController::StaticClass();
	DefaultPawnClass = nullptr;

	if (DataTableEnemyStats == nullptr)
		UE_LOG(LogTemp, Fatal, TEXT("No DataTableEnemyStats loaded !"));
}

void ATDGameMode::OnLose()
{
	UE_LOG(LogTemp, Warning, TEXT("ATDGameMode::OnLose ! "));
}

void ATDGameMode::DecrementEnemyCount()
{
	CurrentEnemyCount--;
	if(!CurrentEnemyCount) EndWave();
}

void ATDGameMode::StartWave()
{
	UE_LOG(LogTemp, Warning, TEXT("ATDGameMode::StartWave ! "));
	CurrentWaveNb++;

	// Get Wave data
	// CurrentEnemyCount =

	// If wave data has simultaneous spawn

	// Start to spawn enemies
	// DataTableEnemyStats->FindRow<FEnemyStats>(EnemyType, TEXT(""));
}

void ATDGameMode::EndWave()
{
	UE_LOG(LogTemp, Warning, TEXT("ATDGameMode::EndWave ! "));
	OnWaveFinished.Broadcast();
}

