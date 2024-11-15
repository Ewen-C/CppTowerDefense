// Fill out your copyright notice in the Description page of Project Settings.


#include "TDWaveTarget.h"
#include "TDEnemy.h"

// Sets default values
ATDWaveTarget::ATDWaveTarget()
{
 	// Set this pawn to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    CurrentHealth = StartingHealth;

    // Create the target mesh and attach the spline to it
    TargetMesh = CreateDefaultSubobject<UStaticMeshComponent>("TargetMesh");
    RootComponent = TargetMesh;

    PathSpline = CreateDefaultSubobject<USplineComponent>("PathSpline");
    PathSpline->SetupAttachment(TargetMesh);

    BoxTrigger = CreateDefaultSubobject<UBoxComponent>("BoxTrigger");
    BoxTrigger->SetupAttachment(TargetMesh);
    
    // Initialize the spline
    PathSpline->SetSplinePoints(
        {FVector(-1000.0f, 0.0f, 0.0f), FVector::ZeroVector},
        ESplineCoordinateSpace::Local,
        true
    );
}

void ATDWaveTarget::BeginPlay()
{
    Super::BeginPlay();

    BoxTrigger->OnComponentBeginOverlap.AddDynamic(this, &ATDWaveTarget::OverlapBegin);
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


void ATDWaveTarget::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if(OtherActor->GetClass() == ATDEnemy::StaticClass())
    {
        ATDEnemy* OverlapEnemy = Cast<ATDEnemy>(OtherActor);
        CurrentHealth -= OverlapEnemy->GetStats()->Damage;
        OnTargetHealthChanged.Broadcast(CurrentHealth);

        OverlapEnemy->Die();
    }
}
