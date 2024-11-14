// Fill out your copyright notice in the Description page of Project Settings.


#include "TDWaveTarget.h"

// Sets default values
ATDWaveTarget::ATDWaveTarget()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    // Create the target mesh and attach the spline to it
    TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>("TargetMesh");
    RootComponent = TargetMesh;

    PathSpline = CreateDefaultSubobject<USplineComponent>("PathSpline");
    PathSpline->SetupAttachment(TargetMesh);
    
    // Initialize the spline
    PathSpline->SetSplinePoints(
        {FVector(-1000.0f, 0.0f, 0.0f), FVector::ZeroVector},
        ESplineCoordinateSpace::Local,
        true
    );
}

FVector ATDWaveTarget::GetPathStartLocation() const
{
    if (PathSpline) return PathSpline->GetLocationAtSplinePoint(0, ESplineCoordinateSpace::World);
    return FVector::ZeroVector;
}


#if WITH_EDITOR
void ATDWaveTarget::PostEditMove(bool bFinished)
{
    Super::PostEditMove(bFinished);
    if (!PathSpline) return;
    
    // Ensure that the spline's last point stays at the target
    int32 LastPoint = PathSpline->GetNumberOfSplinePoints() - 1;
    PathSpline->SetLocationAtSplinePoint(LastPoint, FVector::ZeroVector, ESplineCoordinateSpace::Local);
}
#endif

