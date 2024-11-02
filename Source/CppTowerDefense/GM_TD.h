// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "PS_TD.h"
#include "PC_TD.h"

#include "GM_TD.generated.h"

/**
 * 
 */
UCLASS()
class CPPTOWERDEFENSE_API AGM_TD : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGM_TD();

protected:
	virtual void BeginPlay() override;
	
};
