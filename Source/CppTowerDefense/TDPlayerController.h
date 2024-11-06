// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "Camera/CameraActor.h"
#include "TDPlayerController.generated.h"

UCLASS()
class CPPTOWERDEFENSE_API ATDPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
    ATDPlayerController();

protected:
	virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

    // Input Mapping Context
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    class UInputMappingContext* MappingContextTD;

    // Input Actions
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    class UInputAction* MoveCameraAction;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    class UInputAction* ZoomAction;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    class UInputAction* SelectAction;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    class UInputAction* CancelAction;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    class UInputAction* PauseAction;
	
    // Input Action handlers
    void HandleMoveCamera(const FInputActionValue& InputValue);
    void HandleZoom(const FInputActionValue& InputValue);
    void HandleSelect();
    void HandleCancel();
    void HandlePause();

    // Camera settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    float CameraMoveSpeed = 15.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    float CameraZoomSpeed = 2.5f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    float MinZoom = 500.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
    float MaxZoom = 2000.0f;

    // Cached actors
    UPROPERTY()
	ACameraActor* SceneCamera;
};
