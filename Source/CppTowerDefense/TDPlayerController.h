// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "Camera/CameraActor.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
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
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD|Input")
    class UInputMappingContext* MappingContextTD;

    // Input Actions
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD|Input")
    class UInputAction* MoveCameraAction;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD|Input")
    class UInputAction* ZoomAction;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD|Input")
    class UInputAction* SelectAction;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD|Input")
    class UInputAction* CancelAction;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD|Input")
    class UInputAction* PauseAction;
	
    // Input Action handlers
    void HandleMoveCamera(const FInputActionValue& InputValue);
    void HandleZoom(const FInputActionValue& InputValue);
    void HandleSelect();
    void HandleCancel();
    void HandlePause();

    // Camera settings
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD|Camera")
    float CameraMoveSpeed = 12.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD|Camera")
    float CameraZoomAmount = 22.f;

    UPROPERTY()
    int32 MinZoom = 1;

    UPROPERTY()
    int32 MaxZoom = 15;

    UPROPERTY()
    int32 CurrentZoom = 8;

    // Cached actors
    UPROPERTY()
	ACameraActor* SceneCamera;
	
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TD|Widgets")
	TSubclassOf<UUserWidget> WidgetHud;

    UPROPERTY()
	UUserWidget* SpawnedWidget;
	
};
