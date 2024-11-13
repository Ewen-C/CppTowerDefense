// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "CppTowerDefense/TDDataStructs.h"
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

    float DistanceAlongSpline = 0.0f;
	
	UPROPERTY() 
    USplineComponent* PathToFollow;

    UFUNCTION()
    void PathEndReached();

	UFUNCTION()
	void Die();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
