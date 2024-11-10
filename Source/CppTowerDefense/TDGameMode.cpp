// Fill out your copyright notice in the Description page of Project Settings.


#include "TDGameMode.h"
#include "TDPlayerState.h"
#include "TDPlayerController.h"
#include "Kismet/GameplayStatics.h"

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
	Init();
}

void ATDGameMode::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("ATDGameMode::Init ! "));
}

void ATDGameMode::OnLose()
{
	UE_LOG(LogTemp, Warning, TEXT("ATDGameMode::OnLose ! "));
}

void ATDGameMode::StartWave()
{
	UE_LOG(LogTemp, Warning, TEXT("ATDGameMode::StartWave ! "));
	CurrentWave++;
}

void ATDGameMode::EndWave()
{
	UE_LOG(LogTemp, Warning, TEXT("ATDGameMode::EndWave ! "));
}



