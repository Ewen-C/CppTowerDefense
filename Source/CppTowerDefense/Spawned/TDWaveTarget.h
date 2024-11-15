// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/SplineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TDWaveTarget.generated.h"

// Delegates - must be before the UCLASS ; MULTICAST -> Exposed to BPs
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTargetHealthChanged, int32, NewAmount);

UCLASS()
class CPPTOWERDEFENSE_API ATDWaveTarget : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATDWaveTarget();

	virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    USplineComponent* GetPath() const { return PathSpline; }

    UFUNCTION(BlueprintCallable)
    FVector GetPathStartLocation() const;

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metrics")
	int32 StartingHealth = 20;

	int32 CurrentHealth;
	
    // Mesh of the target
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UStaticMeshComponent* TargetMesh;
	
    // Mesh of the target
    UPROPERTY(VisibleAnywhere, Category = "Components")
    UBoxComponent* BoxTrigger;

    // Spline starting from target
    UPROPERTY(VisibleAnywhere, Category = "Components")
    USplineComponent* PathSpline;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	// Events
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnTargetHealthChanged OnTargetHealthChanged;

#if WITH_EDITOR
	// Move the target along with the spline in editor
    virtual void PostEditMove(bool bFinished) override;
#endif

};
