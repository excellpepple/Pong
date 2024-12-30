// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOverScreen.generated.h"


/**
 *
 */
UCLASS()
class PONG_API UGameOverScreen : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameOver Screen", meta=(BindWidget))
	class UTextBlock* WinnerTxt;

	UFUNCTION(BlueprintCallable)
	void SetWinner(const FText& Text) ;
};
