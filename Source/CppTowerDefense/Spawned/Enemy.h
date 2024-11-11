// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CppTowerDefense/TDGameMode.h"
#include "Enemy.generated.h"

UENUM()
enum class EEnemyType : uint8
{
	Fast,
	Normal,
	Boss
};

USTRUCT(BlueprintType)
struct FEnemyStats : public FTableRowBase  // DataTable -> Inherit from FTableRowBase
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	EEnemyType Type = EEnemyType::Normal;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MaxHeath = 10.f;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float Damage = 1.f;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
	float MovementSpeed = 5.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats")
    int32 MoneyReward = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TSoftObjectPtr<UMaterialInterface> EnemyMaterial;
};

UCLASS()
class CPPTOWERDEFENSE_API AEnemy : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	virtual void Destroyed() override;
};
