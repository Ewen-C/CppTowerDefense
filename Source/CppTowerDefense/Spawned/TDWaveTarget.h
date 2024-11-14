// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TDWaveTarget.generated.h"

UCLASS()
class CPPTOWERDEFENSE_API ATDWaveTarget : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATDWaveTarget();

    UFUNCTION(BlueprintCallable)
    USplineComponent* GetPath() const { return PathSpline; }

    UFUNCTION(BlueprintCallable)
    FVector GetPathStartLocation() const;

protected:
    // Mesh of the target
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* TargetMesh;

    // Spline starting from target
    UPROPERTY(VisibleAnywhere, Category = "Components")
    USplineComponent* PathSpline;

#if WITH_EDITOR
	// Move the target along with the spline in editor
    virtual void PostEditMove(bool bFinished) override;
#endif

};
