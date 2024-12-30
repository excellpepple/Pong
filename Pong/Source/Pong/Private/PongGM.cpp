// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGM.h"

#include "GoalBase.h"
#include "PongHud.h"
#include "ScoreWidget.h"
#include "Kismet/GameplayStatics.h"

void APongGM::Score(GoalType Winner)
{
	switch (Winner)
	{
	case GoalType::Player1:
		Player2Score++;
		UpdateUI();
		break;
	case GoalType::AI:
		Player1Score++;
		UpdateUI();
		break;
	default:
		UE_LOG(LogTemp, Error, TEXT("Invalid Winner: Winner not recognized"));
	}


}

void APongGM::UpdateUI()
{
	APongHud* GameHud = Cast<APongHud>(GetWorld()->GetFirstPlayerController()->GetHUD());
	if(GameHud)
	{
		GameHud->UpdateUI();

		if (Player1Score == MaxScore)
		{
			WinnerText = FText::FromString("Player 1 Wins");
			GameHud->ShowGameOverScreen(WinnerText);
		}
		if (Player2Score == MaxScore)
		{
			WinnerText = FText::FromString("Player 2 Wins");
			GameHud->ShowGameOverScreen(WinnerText);
		}

	}
}

void APongGM::PauseGame()
{
	APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(GetWorld()));
	if (MyPlayer != NULL)
	{
		bIsPaused = true;
		MyPlayer->SetPause(bIsPaused);
	}
}
