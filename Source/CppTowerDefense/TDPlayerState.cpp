// Fill out your copyright notice in the Description page of Project Settings.


#include "TDPlayerState.h"


void ATDPlayerState::BeginPlay()
{
	Super::BeginPlay();
	CurrentMoney = StartingMoney;
	
	UE_LOG(LogTemp, Warning, TEXT("UGI_TD::Init ! Starting Money : %d !"), StartingMoney);
}


