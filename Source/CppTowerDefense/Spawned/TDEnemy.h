// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "CppTowerDefense/TDDataStructs.h"
#include "TDEnemy.generated.h"

// Delegates - must be before the UCLASS ; MULTICAST -> Exposed to BPs
DECLARE_MULTICAST_DELEGATE(FOnEnemyDeath);

UCLASS()
class CPPTOWERDEFENSE_API ATDEnemy : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATDEnemy();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void InitializeSpline(USplineComponent* PathToFollow);
	void InitializeStats(const FTDEnemyStats* Stats);

protected:	
    // Mesh of the enemy
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* EnemyMesh;
	
	UPROPERTY() 
    USplineComponent* SplineToFollow;

    float MoveSpeed;
    float DistanceAlongSpline;
	float SplineLength;

    UFUNCTION()
	void MoveAlongSpline(float DeltaTime);

	UFUNCTION()
	void Die();

public:
	// Events
	FOnEnemyDeath OnEnemyDeath;
};
