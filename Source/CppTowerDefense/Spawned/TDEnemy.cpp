// Fill out your copyright notice in the Description page of Project Settings.


#include "TDEnemy.h"

// Sets default values
ATDEnemy::ATDEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>("EnemyMesh");
    RootComponent = EnemyMesh;
}

void ATDEnemy::InitializeSpline(USplineComponent* PathToFollow)
{
	SplineToFollow = PathToFollow;
	SplineLength = PathToFollow->GetSplineLength();
	DistanceAlongSpline = 0.0f;
}

void ATDEnemy::InitializeStats(const FTDEnemyStats* Stats)
{
	MoveSpeed = Stats->MovementSpeed;

	if(!Stats->EnemyMesh.IsNull()) 
	{
		EnemyMesh->SetStaticMesh(Stats->EnemyMesh.Get());

		UE_LOG(LogTemp, Warning, TEXT("Material : %s"), *Stats->EnemyMaterial.GetAssetName());
		
		if(!Stats->EnemyMaterial.IsNull()) EnemyMesh->SetMaterial(0, Stats->EnemyMaterial.LoadSynchronous());
		else UE_LOG(LogTemp, Error, TEXT("No Material defined for Enemy %p !"), this->GetClass());
	}
	else UE_LOG(LogTemp, Error, TEXT("No Mesh defined for Enemy %p !"), this->GetClass());
}

// Called every frame
void ATDEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveAlongPath(DeltaTime);
}

void ATDEnemy::MoveAlongPath(float DeltaTime)
{
	DistanceAlongSpline += MoveSpeed * DeltaTime;

	// Check if end reached
	if(DistanceAlongSpline >= SplineLength) Die();
	
    // Update position and rotation
    FVector NewLocation = SplineToFollow->GetLocationAtDistanceAlongSpline(
        DistanceAlongSpline, 
        ESplineCoordinateSpace::World
    );
    
    FRotator NewRotation = SplineToFollow->GetRotationAtDistanceAlongSpline(
        DistanceAlongSpline, 
        ESplineCoordinateSpace::World
    );

    SetActorLocationAndRotation(NewLocation, NewRotation);
}

void ATDEnemy::PathEndReached()
{
	
}

void ATDEnemy::Die()
{
	// Can't get GameMode -> circular dependency
	
	// if(ATDGameMode* Gm_Td = Cast<ATDGameMode>(GetWorld()->GetAuthGameMode()))
	// 	Gm_Td->DecrementEnemyCount();
	// else
	// 	UE_LOG(LogTemp, Error, TEXT("Can't get GameMode in Enemy ! "));;
	// 	
	
	UE_LOG(LogTemp, Log, TEXT("Enemy died !"));
	
	Destroy();	
}

