// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemy::PathEndReached()
{
	
}

void AEnemy::Die()
{
	if(ATDGameMode* Gm_Td = Cast<ATDGameMode>(GetWorld()->GetAuthGameMode()))
		Gm_Td->DecrementEnemyCount();
	else
		UE_LOG(LogTemp, Error, TEXT("Can't get GameMode in Enemy ! "));;
		
	Destroy();
	
}

