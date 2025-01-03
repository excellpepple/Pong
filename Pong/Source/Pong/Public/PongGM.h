﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GoalBase.h"
#include "PongGM.generated.h"


class APongHud;
/**
 *
 */
UCLASS()
class PONG_API APongGM : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Score System")
	int Player1Score;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Score System")
	int Player2Score;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Score System")
	int MaxScore{10};
	UPROPERTY()
	FText WinnerText;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsPaused = false;

	UFUNCTION(BlueprintCallable, Category="Score System")
	void Score(GoalType Winner);
	UFUNCTION(BlueprintCallable, Category="Score System")
	void UpdateUI();
	UFUNCTION(BlueprintCallable, Category="Pause System")
	void PauseGame();

};
