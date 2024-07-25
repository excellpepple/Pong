// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePaddle.generated.h"



UCLASS()
class PONG_API ABasePaddle : public APawn
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pong | Mesh Component")
	TObjectPtr<UStaticMeshComponent> MeshComponent;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pong | Movement Controls")
	float PaddleSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="")
	float m_Direction;
	FVector InitialPositon;


public:
	// Sets default values for this pawn's properties
	ABasePaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MovePaddle(float Direction);
};
