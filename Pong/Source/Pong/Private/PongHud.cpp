// Fill out your copyright notice in the Description page of Project Settings.


#include "PongHud.h"

#include "GameOverScreen.h"

void APongHud::UpdateUI()
{
	if (ScoreWidget)
	{
		ScoreWidget->UpdateScores();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid ScoreWidget: Please asign a Score widget class "))
	}
}

void APongHud::ShowGameOverScreen(const FText& Winner)
{
	if(GameOverScreen)
	{
		FText msg = Winner;
		GameOverScreen->AddToViewport(1);
		GameOverScreen->SetWinner(msg);

	}

}
