// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverScreen.h"

#include "Components/TextBlock.h"

void UGameOverScreen::NativeConstruct()
{
	Super::NativeConstruct();
	if (!WinnerTxt)
	{
		UE_LOG(LogTemp, Error, TEXT("WinnerTxt is not bound correctly"));
	}
}

void UGameOverScreen::SetWinner(const FText& Text)
{
	FText Winner = FText(Text);
	if (WinnerTxt)
	{
		WinnerTxt->SetText(Winner);
	} else
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid Textblock: WinnerTxt is null"));
	}
}
