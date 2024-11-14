// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TDPlayerState.generated.h"

// Delegates - must be before the UCLASS ; MULTICAST -> Exposed to BPs
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInsufficientFunds);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMoneyChanged, int32, NewAmount);

UCLASS()
class CPPTOWERDEFENSE_API ATDPlayerState : public APlayerState
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	int32 CurrentMoney;

public:
	// Functions
    UFUNCTION(BlueprintCallable, Category = "Resources")
    void AddMoney(int32 Amount);
    
    UFUNCTION(BlueprintCallable, Category = "Resources")
    bool SpendMoney(int32 Amount);
    
    UFUNCTION(BlueprintPure, Category = "Resources")
    int32 GetCurrentMoney() const { return CurrentMoney; }

	// Events
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnInsufficientFunds OnInsufficientFunds;
	
	UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnMoneyChanged OnMoneyChanged;
	
};
