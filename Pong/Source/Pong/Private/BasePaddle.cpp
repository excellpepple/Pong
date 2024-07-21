// Fill out your copyright notice in the Description page of Project Settings.


#include "Pong/Public/BasePaddle.h"


// Sets default values
ABasePaddle::ABasePaddle()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = MeshComponent;
	PaddleSpeed = 300;
}

// Called when the game starts or when spawned
void ABasePaddle::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABasePaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABasePaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

