// Fill out your copyright notice in the Description page of Project Settings.


#include "TDPlayerState.h"

#include "TDGameMode.h"


void ATDPlayerState::BeginPlay()
{
	Super::BeginPlay();

	if(const ATDGameMode* Gm_Td = Cast<ATDGameMode>(GetWorld()->GetAuthGameMode()))
		AddMoney(Gm_Td->StartingMoney);
}

void ATDPlayerState::AddMoney(const int32 Amount)
{
	if(Amount) CurrentMoney += Amount;
	UE_LOG(LogTemp, Warning, TEXT("ATDPlayerState::AddMoney %i -> %i !"), Amount, CurrentMoney);
}


