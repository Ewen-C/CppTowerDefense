// Fill out your copyright notice in the Description page of Project Settings.


#include "TDPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


ATDPlayerController::ATDPlayerController()
{
	// Show cursor
    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;
}

void ATDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(this);
	if (!(PlayerController && MappingContextTD)) return;
	
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
	    ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(MappingContextTD, 0);
    }

}

void ATDPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if (UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(InputComponent))
    {
        // Binding actions
        EIC->BindAction(MoveCameraAction, ETriggerEvent::Triggered, this, &ATDPlayerController::HandleMoveCamera);
        EIC->BindAction(ZoomAction, ETriggerEvent::Triggered, this, &ATDPlayerController::HandleZoom);
        EIC->BindAction(SelectAction, ETriggerEvent::Started, this, &ATDPlayerController::HandleSelect);
        EIC->BindAction(CancelAction, ETriggerEvent::Started, this, &ATDPlayerController::HandleCancel);
        EIC->BindAction(PauseAction, ETriggerEvent::Started, this, &ATDPlayerController::HandlePause);
    }
}

void ATDPlayerController::HandleMoveCamera(const FInputActionValue& InputValue) 
{
	UE_LOG(LogTemp, Warning, TEXT("HandleMoveCamera %s ! "), *InputValue.Get<FInputActionValue::Axis2D>().ToString());
}

void ATDPlayerController::HandleZoom(const FInputActionValue& InputValue) 
{
	UE_LOG(LogTemp, Warning, TEXT("HandleZoom %f ! "), InputValue.GetMagnitude());
}

void ATDPlayerController::HandleSelect() 
{
	UE_LOG(LogTemp, Warning, TEXT("HandleSelect ! "));
}

void ATDPlayerController::HandleCancel() 
{
	UE_LOG(LogTemp, Warning, TEXT("HandleCancel ! "));
}

void ATDPlayerController::HandlePause() 
{
	UE_LOG(LogTemp, Warning, TEXT("HandlePause ! "));
}


