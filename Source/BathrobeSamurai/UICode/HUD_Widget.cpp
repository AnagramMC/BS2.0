// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "HUD_Widget.h"

AHUD_Widget::AHUD_Widget()
{
	static ConstructorHelpers::FObjectFinder<UFont> HUDFontOb(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	HUDFont = HUDFontOb.Object;
}

void AHUD_Widget::DrawHUD()
{
	Super::DrawHUD();

	//Get screen dimensions
	FVector2D ScreenDimensions = FVector2D(Canvas->SizeX, Canvas->SizeY);

	// find center of the Canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

	FColor HUDColor;

	//Get player and print health
	CurPlayer = Cast<ABSPlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (CurPlayer)
	{
	//	fHealth = CurPlayer->getHitPoints();
		HealthText = FString::Printf(TEXT("%10.1f"), FMath::Abs(fHealth));
		DrawText("Health: ", FColor::Green, 50, 50, HUDFont);

	//	fSuper = CurPlayer->getSuperMeter();
		SuperText = FString::Printf(TEXT("%10.1f"), FMath::Abs(fSuper));
		DrawText("Super: ", FColor::Blue, 50, 120, HUDFont);

		if (fHealth > 100 / 2)
			HUDColor = FColor::Green;
		if (fHealth <= 100 / 2 && fHealth > 100 / 4)
			HUDColor = FColor::Yellow;
		if (fHealth <= 100 / 4)
			HUDColor = FColor::Red;

		//Draws line where Length = Health
		if (fHealth > 0.f)
		{
			Draw2DLine(50, 80, (50 + FMath::Abs(fHealth)) * 2, 80, HUDColor);
			DrawText(HealthText, HUDColor, 80, 90, HUDFont);
		}
		else
		{
			Draw2DLine(0, 0, 0, 0, FColor::White);
			DrawText("0", HUDColor, 80, 90, HUDFont);
		}

		//Draw Super Meter
		Draw2DLine(50, 150, (50 + FMath::Abs(fSuper)), 150, FColor::Blue);
		DrawText(SuperText, FColor::Blue, 80, 160, HUDFont);
	}

	if (GameManagerClass)
	{
		GameManager = NewObject<UGameManager>(this, GameManagerClass, TEXT("GameManager"));
		if (GameManager)
		{
	//		iComboCount = GameManager->GetComboCount();
	//		ComboText = FString::Printf(TEXT("%10.1f"), FMath::Abs(iComboCount));

	//		if (iComboCount > 1)
	//		{
	//			DrawText("Combo!", FColor::Red, (ScreenDimensions.X - 100), 50, HUDFont);
	//			DrawText(ComboText, FColor::Red, (ScreenDimensions.X - 100), 80, HUDFont);
	//		}
		}
	}
}


