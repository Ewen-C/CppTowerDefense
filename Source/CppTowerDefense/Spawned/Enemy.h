// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemy.generated.h"

// Delegates - must be before the UCLASS ; NO MULTICAST -> Not exposed to BPs
DECLARE_DYNAMIC_DELEGATE(FOnEnemyDeath);

UENUM()
enum class EEnemyType : uint8
{
	Fast,
	Normal,
	Boss
};

UCLASS()
class CPPTOWERDEFENSE_API AEnemy : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	virtual void Destroyed() override;

	// Events
	FOnEnemyDeath OnEnemyDeath;
};
