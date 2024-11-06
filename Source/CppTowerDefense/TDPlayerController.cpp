// Fill out your copyright notice in the Description page of Project Settings.


#include "TDPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Array.h"


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

    AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass());
	SceneCamera = Cast<ACameraActor>(FoundActor);

}


void ATDPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

	UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(InputComponent);

    if (EIC == nullptr)
    {
    	UE_LOG(LogTemp, Fatal, TEXT("Failed to bind actions ! "));
    	return;
    }
	
    // Binding all actions
    EIC->BindAction(MoveCameraAction, ETriggerEvent::Triggered, this, &ATDPlayerController::HandleMoveCamera);
    EIC->BindAction(ZoomAction, ETriggerEvent::Triggered, this, &ATDPlayerController::HandleZoom);
    EIC->BindAction(SelectAction, ETriggerEvent::Started, this, &ATDPlayerController::HandleSelect);
    EIC->BindAction(CancelAction, ETriggerEvent::Started, this, &ATDPlayerController::HandleCancel);
    EIC->BindAction(PauseAction, ETriggerEvent::Started, this, &ATDPlayerController::HandlePause);
}

void ATDPlayerController::HandleMoveCamera(const FInputActionValue& InputValue) 
{
	UE_LOG(LogTemp, Warning, TEXT("HandleMoveCamera %s ! "), *InputValue.Get<FInputActionValue::Axis2D>().ToString());

	FVector2D CameraMovement = InputValue.Get<FInputActionValue::Axis2D>() * CameraMoveSpeed;

	SceneCamera->SetActorLocation(SceneCamera->GetActorLocation() + FVector(CameraMovement, 0));
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


