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
		Player1Score++;
		UpdateUI();
		break;
	case GoalType::AI:
		Player2Score++;
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
	}
}
