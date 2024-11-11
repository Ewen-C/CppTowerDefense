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

	// Start to spawn enemies

	// CurrentEnemyCount = 
}

void ATDGameMode::EndWave()
{
	UE_LOG(LogTemp, Warning, TEXT("ATDGameMode::EndWave ! "));
	OnWaveFinished.Broadcast();
}



