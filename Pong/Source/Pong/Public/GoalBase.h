// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GoalBase.generated.h"

UENUM(BlueprintType)
enum class GoalType: uint8 { Player1, AI };


UCLASS()
class PONG_API AGoalBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGoalBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Goal Settings | Goal Type")
	GoalType GoalOwner;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
