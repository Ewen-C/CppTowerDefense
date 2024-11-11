// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TDDataStructs.generated.h"

UENUM()
enum class EEnemyType : uint8
{
	Fast,
	Normal,
	Boss
};

USTRUCT(BlueprintType)
struct FTDEnemyStats : public FTableRowBase  // DataTable -> Inherit from FTableRowBase
{
	GENERATED_BODY()

	// RowName not used

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

USTRUCT(BlueprintType)
struct FTDWaveData : public FTableRowBase  // DataTable -> Inherit from FTableRowBase
{
	GENERATED_BODY()
	
    // TMap in USTRUCT -> Must use UPROPERTY(meta = (TMapKey))
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (TMapKey)) 
    TMap<EEnemyType, int32> EnemyComposition;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Settings")
    float SpawnInterval = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Settings")
    bool SpawnTypesSimultaneously = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Settings")
    int WaveMoneyReward = 5;	
};