// Fill out your copyright notice in the Description page of Project Settings.


#include "Pong/Public/PlayerPaddle.h"
#include "InputActionValue.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


// Sets default values
APlayerPaddle::APlayerPaddle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void APlayerPaddle::BeginPlay()
{
	Super::BeginPlay();
	if(APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* InputSystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			InputSystem->AddMappingContext(MappingContext, 0);
		}
	}
}

void APlayerPaddle::Move(const FInputActionValue& Value)
{
	float MoveInput = Value.Get<float>();
	MovePaddle(MoveInput);
}

void APlayerPaddle::StopMovement()
{
	MovePaddle(0.f);
}

// Called every frame
void APlayerPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// if (m_Direction == 0)
	// {
	// 	FVector CurrentLocation = GetActorLocation();
	// 	FVector TargetDirection = FVector(0, 0, 0); // No movement
	// 	FVector TargetLocation = FMath::VInterpTo(CurrentLocation, CurrentLocation + TargetDirection, DeltaTime, 5.0f);
	// 	SetActorLocation(TargetLocation);
	// }
}

// Called to bind functionality to input
void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("Added Enhanced Input"))
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayerPaddle::Move);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &APlayerPaddle::StopMovement);
	}

}

