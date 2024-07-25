// Fill out your copyright notice in the Description page of Project Settings.


#include "Pong/Public/AIPaddle.h"

#include "Ball.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AAIPaddle::AAIPaddle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AAIPaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();
	ABall* Target = Cast<ABall>(UGameplayStatics::GetActorOfClass(GetWorld(), ABall::StaticClass()));
	if (Target)
	{
		FVector BallLocation = Target->GetActorLocation();
		FVector NewLocation{ CurrentLocation.X, BallLocation.Y, CurrentLocation.Z};
		FVector TargetLocation  = FMath::VInterpConstantTo( CurrentLocation, NewLocation, DeltaTime, PaddleSpeed);
		SetActorLocation(TargetLocation);
	}
	else
	{
		SetActorLocation(CurrentLocation); //BUG: AI moves even after loosing sight of the ball
	}
}

// Called to bind functionality to input
void AAIPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

