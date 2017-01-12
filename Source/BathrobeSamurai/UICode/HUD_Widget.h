// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "BSPlayer.h"
#include "GameManager/GameManager.h"
#include "HUD_Widget.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API AHUD_Widget : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY()
		UFont* HUDFont;

public:
	AHUD_Widget();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameManager")
		TSubclassOf<UGameManager> GameManagerClass;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
		float fHealth = 1.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
		float fSuper = 1.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
		uint8 iComboCount = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
		uint8 iKillCount = 1;


	UGameManager* GameManager;
	ABSPlayer* CurPlayer;
	FString HealthText;
	FString SuperText;
	FString ComboText;
	FString KillText;
};
