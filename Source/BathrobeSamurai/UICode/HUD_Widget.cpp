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

	if (HealthBase)
	{
		DrawTextureSimple(HealthBase, 50, 50, 0.4f);
	}
	if (SuperBase)
	{
		DrawTextureSimple(SuperBase, 50, 50, 0.4f);
	}

	//Get player and print health
	CurPlayer = Cast<ABSPlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (CurPlayer)
	{
	//	fHealth = CurPlayer->getHitPoints();
		/*HealthText = FString::Printf(TEXT("%10.1f"), FMath::Abs(fHealth/10.f));
		DrawText("Health: ", FColor::Green, 50, 50, HUDFont);*/

	//	fSuper = CurPlayer->getSuperMeter();
		/*SuperText = FString::Printf(TEXT("%10.1f"), FMath::Abs(fSuper));
		DrawText("Super: ", FColor::Blue, 50, 120, HUDFont);*/

		//Draws line where Length = Health
		/*if (fHealth > 0.f)
		{
			Draw2DLine(50, 80, (50 + FMath::Abs(fHealth/10.f)) * 2, 80, HUDColor);
			DrawText(HealthText, HUDColor, 80, 90, HUDFont);
		}
		else
		{
			Draw2DLine(0, 0, 0, 0, FColor::White);
			DrawText("0", HUDColor, 80, 90, HUDFont);
		}*/

		if (fHealth == 1000.f)
			DrawTextureSimple(Health100, 50, 50, 0.4f);
		if (fHealth >= 900.f && fHealth < 1000.f)
			DrawTextureSimple(Health90, 50, 50, 0.4f);
		if (fHealth >= 800.f && fHealth < 900.f)
			DrawTextureSimple(Health80, 50, 50, 0.4f);
		if (fHealth >= 700.f && fHealth < 800.f)
			DrawTextureSimple(Health70, 50, 50, 0.4f);
		if (fHealth >= 600.f && fHealth < 700.f)
			DrawTextureSimple(Health60, 50, 50, 0.4f);
		if (fHealth >= 500.f && fHealth < 600.f)
			DrawTextureSimple(Health50, 50, 50, 0.4f);
		if (fHealth >= 400.f && fHealth < 500.f)
			DrawTextureSimple(Health40, 50, 50, 0.4f);
		if (fHealth >= 300.f && fHealth < 400.f)
			DrawTextureSimple(Health30, 50, 50, 0.4f);
		if (fHealth >= 200.f && fHealth < 300.f)
			DrawTextureSimple(Health20, 50, 50, 0.4f);
		if (fHealth >= 100.f && fHealth < 200.f)
			DrawTextureSimple(Health10, 50, 50, 0.4f);

		if (fSuper == 1000.f)
			DrawTextureSimple(Super100, 50, 50, 0.4f);
		if (fSuper >= 900.f && fSuper < 1000.f)
			DrawTextureSimple(Super90, 50, 50, 0.4f);
		if (fSuper >= 800.f && fSuper < 900.f)
			DrawTextureSimple(Super80, 50, 50, 0.4f);
		if (fSuper >= 700.f && fSuper < 800.f)
			DrawTextureSimple(Super70, 50, 50, 0.4f);
		if (fSuper >= 600.f && fSuper < 700.f)
			DrawTextureSimple(Super60, 50, 50, 0.4f);
		if (fSuper >= 500.f && fSuper < 600.f)
			DrawTextureSimple(Super50, 50, 50, 0.4f);
		if (fSuper >= 400.f && fSuper < 500.f)
			DrawTextureSimple(Super40, 50, 50, 0.4f);
		if (fSuper >= 300.f && fSuper < 400.f)
			DrawTextureSimple(Super30, 50, 50, 0.4f);
		if (fSuper >= 200.f && fSuper < 300.f)
			DrawTextureSimple(Super20, 50, 50, 0.4f);
		if (fSuper >= 100.f && fSuper < 200.f)
			DrawTextureSimple(Super10, 50, 50, 0.4f);

		/*if (fHealth > 100 / 2)
			HUDColor = FColor::Green;
		if (fHealth <= 100 / 2 && fHealth > 100 / 4)
			HUDColor = FColor::Yellow;
		if (fHealth <= 100 / 4)
			HUDColor = FColor::Red;*/

		//Draw Super Meter
		/*Draw2DLine(50, 150, (50 + FMath::Abs(fSuper)), 150, FColor::Blue);
		DrawText(SuperText, FColor::Blue, 80, 160, HUDFont);*/
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


