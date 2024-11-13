// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "WaveTarget.generated.h"

UCLASS()
class CPPTOWERDEFENSE_API AWaveTarget : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWaveTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
