// Fill out your copyright notice in the Description page of Project Settings.


#include "TDPlayerController.h"

ATDPlayerController::ATDPlayerController()
{
	// Show cursor
    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;
}

void ATDPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Input setup

	APlayerController* PlayerController = Cast<APlayerController>(this);
	if (!(PlayerController && MappingContextTD)) UE_LOG(LogTemp, Fatal, TEXT("Failed input setup ! "));;
	
    if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
	    ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
    {
        Subsystem->AddMappingContext(MappingContextTD, 0);
    }

    AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass());
	SceneCamera = Cast<ACameraActor>(FoundActor);

	// HUD setup

    if (WidgetHud == nullptr) UE_LOG(LogTemp, Fatal, TEXT("No WidgetHud assigned ! "));

	SpawnedWidget = CreateWidget(this, WidgetHud);
	SpawnedWidget->AddToViewport();
}


void ATDPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

	UEnhancedInputComponent* EIC = CastChecked<UEnhancedInputComponent>(InputComponent);

    if (EIC == nullptr) UE_LOG(LogTemp, Fatal, TEXT("Failed to bind actions ! "));
	
    // Binding all actions
    EIC->BindAction(MoveCameraAction, ETriggerEvent::Triggered, this, &ATDPlayerController::HandleMoveCamera);
    EIC->BindAction(ZoomAction, ETriggerEvent::Triggered, this, &ATDPlayerController::HandleZoom);
    EIC->BindAction(SelectAction, ETriggerEvent::Started, this, &ATDPlayerController::HandleSelect);
    EIC->BindAction(CancelAction, ETriggerEvent::Started, this, &ATDPlayerController::HandleCancel);
    EIC->BindAction(PauseAction, ETriggerEvent::Started, this, &ATDPlayerController::HandlePause);
}

void ATDPlayerController::HandleMoveCamera(const FInputActionValue& InputValue) 
{
	FVector2D CameraMovement = InputValue.Get<FInputActionValue::Axis2D>() * CameraMoveSpeed;
	UE_LOG(LogTemp, Warning, TEXT("HandleMoveCamera %s ! "), *CameraMovement.ToString());
	CameraMovement *= 0.25 + (MaxZoom - CurrentZoom + 1) * 0.25; // Move slower when zoomed in

	SceneCamera->SetActorLocation(SceneCamera->GetActorLocation() + FVector(CameraMovement, 0));
}

void ATDPlayerController::HandleZoom(const FInputActionValue& InputValue) 
{
	int ZoomDirection = InputValue.GetMagnitude();
	UE_LOG(LogTemp, Warning, TEXT("HandleZoom %d ! "), ZoomDirection);

	// Clamp to max & min
	if((ZoomDirection > 0 && CurrentZoom == MaxZoom) || (ZoomDirection < 0 && CurrentZoom == MinZoom)) return;

	if(ZoomDirection > 0)
	{
		CurrentZoom++;
		SceneCamera->SetActorLocation(SceneCamera->GetActorLocation() + FVector(CameraZoomAmount, 0, -CameraZoomAmount));
	}
	else
	{
		CurrentZoom--;
		SceneCamera->SetActorLocation(SceneCamera->GetActorLocation() + FVector(-CameraZoomAmount, 0, CameraZoomAmount));
	}
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


