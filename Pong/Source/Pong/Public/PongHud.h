// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ScoreWidget.h"
#include "GameFramework/HUD.h"
#include "PongHud.generated.h"

class UGameOverScreen;
class UScoreWidget;
class UTextBlock;
/**
 *
 */
UCLASS()
class PONG_API APongHud : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UScoreWidget* ScoreWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UGameOverScreen* GameOverScreen;

	// Functions
	UFUNCTION(BlueprintCallable)
	void UpdateUI();
	UFUNCTION(BlueprintCallable)
	void ShowGameOverScreen(const FText& Winner);


};
