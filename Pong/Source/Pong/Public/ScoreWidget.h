// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ScoreWidget.generated.h"

class UTextBlock;
/**
 *
 */
UCLASS()
class PONG_API UScoreWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* Player1Txt;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTextBlock* Player2Txt;


	UFUNCTION(BlueprintCallable)
	void UpdateScores();

};
