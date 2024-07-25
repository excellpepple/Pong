// Fill out your copyright notice in the Description page of Project Settings.


#include "Pong/Public/Ball.h"


// Sets default values
ABall::ABall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball Mesh"));
	MeshComponent->SetSimulatePhysics(true);
	MeshComponent->BodyInstance.bLockZTranslation = true;

	// Bind the OnHit function to the OnComponentHit event
	MeshComponent->OnComponentHit.AddDynamic(this, &ABall::OnHit);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	float Direction = FMath::RandRange(0, 1) * 2 - 1;//FMath::RandRange(0, 1) * 2 - 1;
	FVector InitialVelocity = FVector(Direction * Speed, FMath::RandRange(-1.0f, 1.0f) * Speed, 0);
    MeshComponent->SetPhysicsLinearVelocity(InitialVelocity);
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABall::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	FVector NormalImpulse, const FHitResult& Hit)
{
	Speed += ReboundForce;
	FVector CurrentBallVelocity = MeshComponent->GetPhysicsLinearVelocity().GetSafeNormal() * Speed;
	FVector LinearVelocity = CurrentBallVelocity.GetClampedToMaxSize(Speed);
	MeshComponent->SetPhysicsLinearVelocity(LinearVelocity);
}

