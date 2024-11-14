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

void ATDGameMode::BeginPlay()
{
	Super::BeginPlay();

	WaveManager = Cast<ATDWaveManager>(GetWorld()->SpawnActor(ATDWaveManager::StaticClass()));
	WaveManager->InitDT(DTWaveComposition, DTEnemyStats);

	WaveManager->OnAllEnemiesDied.AddUObject(this, &ATDGameMode::EndWave); // Bind event
}

void ATDGameMode::OnLose()
{
	UE_LOG(LogTemp, Warning, TEXT("ATDGameMode::OnLose ! "));
}

void ATDGameMode::StartWave()
{
	if (DTEnemyStats == nullptr || DTWaveComposition == nullptr)
		UE_LOG(LogTemp, Fatal, TEXT("DataTables missing !"));
	
	UE_LOG(LogTemp, Warning, TEXT("ATDGameMode::StartWave ! "));
	WaveManager->StartWave();
}

void ATDGameMode::EndWave()
{
	UE_LOG(LogTemp, Warning, TEXT("ATDGameMode::EndWave ! "));
	OnEnableNewWave.Broadcast();
}

