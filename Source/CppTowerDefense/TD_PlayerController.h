// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TD_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CPPTOWERDEFENSE_API ATD_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;	
};
