// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CppTowerDefense/TDDataStructs.h"
#include "CppTowerDefense/TDGameMode.h"
#include "Enemy.generated.h"

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

	EEnemyType MyEnemyType;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	virtual void Destroyed() override;
};
