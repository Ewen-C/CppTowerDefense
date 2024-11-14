// Fill out your copyright notice in the Description page of Project Settings.


#include "TDEnemy.h"

// Sets default values
ATDEnemy::ATDEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATDEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATDEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
	// Destroy();
	
	UE_LOG(LogTemp, Log, TEXT("Enemy died"));
	
}

