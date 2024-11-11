// Fill out your copyright notice in the Description page of Project Settings.


#include "TDGameMode.h"
#include "TDPlayerState.h"


void ATDPlayerState::BeginPlay()
{
	Super::BeginPlay();

	if(const ATDGameMode* Gm_Td = Cast<ATDGameMode>(GetWorld()->GetAuthGameMode()))
		AddMoney(Gm_Td->StartingMoney);
	else
		UE_LOG(LogTemp, Fatal, TEXT("Can't get GameMode in TDPlayerState ! "));
}

void ATDPlayerState::AddMoney(const int32 Amount)
{
	if(!Amount) return;
	
	CurrentMoney += Amount;
	UE_LOG(LogTemp, Warning, TEXT("ATDPlayerState::AddMoney %i -> %i !"), Amount, CurrentMoney);
	OnMoneyChanged.Broadcast(CurrentMoney);
}

bool ATDPlayerState::SpendMoney(const int32 Amount)
{
	if(CurrentMoney < Amount)
	{
		OnInsufficientFunds.Broadcast();
		return false;
	}
	
	CurrentMoney -= Amount;
	OnMoneyChanged.Broadcast(CurrentMoney);
	return true;
}

