// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC_TD.generated.h"

/**
 * 
 */
UCLASS()
class CPPTOWERDEFENSE_API APC_TD : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;	
};
