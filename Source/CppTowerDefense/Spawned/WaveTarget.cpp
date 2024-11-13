// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveTarget.h"

// Sets default values
AWaveTarget::AWaveTarget()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWaveTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaveTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

