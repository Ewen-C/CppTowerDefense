// Fill out your copyright notice in the Description page of Project Settings.


#include "GI_TD.h"


void UGI_TD::Init()
{
	Super::Init();
	
	UE_LOG(LogTemp, Warning, TEXT("UGI_TD::Init ! Starting Money : %d !"), Money);
}

