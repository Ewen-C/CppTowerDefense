// Fill out your copyright notice in the Description page of Project Settings.


#include "PS_TD.h"


void APS_TD::BeginPlay()
{
	Super::BeginPlay();
	CurrentMoney = StartingMoney;
	
	UE_LOG(LogTemp, Warning, TEXT("UGI_TD::Init ! Starting Money : %d !"), StartingMoney);
}


