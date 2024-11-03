// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PS_TD.generated.h"

/**
 * 
 */
UCLASS()
class CPPTOWERDEFENSE_API APS_TD : public APlayerState
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
	int32 CurrentMoney;

public:
	UPROPERTY(BlueprintReadWrite)
	int32 StartingMoney = 8;

    UFUNCTION(BlueprintCallable, Category = "Resources")
    void AddMoney(int32 Amount) { if(Amount) CurrentMoney += Amount; }
    
    UFUNCTION(BlueprintCallable, Category = "Resources")
    bool SpendMoney(int32 Amount) { if(CurrentMoney < Amount) return false; CurrentMoney -= Amount; return true; }
    
    UFUNCTION(BlueprintPure, Category = "Resources")
    int32 GetCurrentMoney() const { return CurrentMoney; }
	
};
