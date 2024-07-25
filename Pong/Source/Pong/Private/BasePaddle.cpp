// Fill out your copyright notice in the Description page of Project Settings.


#include "Pong/Public/BasePaddle.h"

// Sets default values
ABasePaddle::ABasePaddle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(RootComponent);



	PaddleSpeed = 300;
}

// Called when the game starts or when spawned
void ABasePaddle::BeginPlay()
{
	Super::BeginPlay();
	InitialPositon = GetActorLocation();
}

// Called every frame
void ABasePaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (m_Direction != 0.f)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector TargetLocation = CurrentLocation + FVector(0, m_Direction * PaddleSpeed *DeltaTime, 0);
		// FVector TargetLocation  = FMath::VInterpTo( CurrentLocation, CurrentLocation+TargetDirection, DeltaTime, PaddleSpeed);
		SetActorLocation(TargetLocation);
	}

}

// Called to bind functionality to input
void ABasePaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABasePaddle::MovePaddle(float Direction)
{
	m_Direction = Direction;
}

