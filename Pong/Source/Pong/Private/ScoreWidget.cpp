// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreWidget.h"

#include "PongGM.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UScoreWidget::UpdateScores()
{
	APongGM* GameMode = Cast<APongGM>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		FString P1Str = FString::Printf(TEXT("%i"), GameMode->Player1Score);
		FString P2Str = FString::Printf(TEXT("%i"), GameMode->Player2Score);
		Player1Txt->SetText(FText::FromString(P1Str));
		Player2Txt->SetText(FText::FromString(P2Str));
	}
}
