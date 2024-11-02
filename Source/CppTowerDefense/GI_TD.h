// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GI_TD.generated.h"

/**
 * 
 */
UCLASS()
class CPPTOWERDEFENSE_API UGI_TD : public UGameInstance
{
	GENERATED_BODY()

protected:
	virtual void Init() override;
	
};
