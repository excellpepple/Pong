// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class PONG_API ABall : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABall();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ball Mesh Component")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ball Speed Controls")
	float Speed{200.f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ball Speed Controls")
	float MaxSpeed{1000.f};
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Ball Speed Controls")
	float ReboundForce{30.f};


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		FVector NormalImpulse, const FHitResult& Hit);
};
