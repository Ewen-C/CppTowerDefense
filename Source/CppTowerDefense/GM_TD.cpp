// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_TD.h"

#include "Kismet/GameplayStatics.h"

AGM_TD::AGM_TD()
{
	// Setup GameMode

	PlayerStateClass = APS_TD::StaticClass();
	PlayerControllerClass = APC_TD::StaticClass();
	DefaultPawnClass = nullptr;
}

void AGM_TD::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void AGM_TD::Init()
{
	
}

void AGM_TD::OnLose()
{
	
}

void AGM_TD::StartWave()
{
	CurrentWave++;
}

void AGM_TD::EndWave()
{
	
}



