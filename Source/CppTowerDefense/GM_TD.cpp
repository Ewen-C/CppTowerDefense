// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_TD.h"

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
}