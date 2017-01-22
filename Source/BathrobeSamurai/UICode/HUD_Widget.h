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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
		float fHealth = 1.f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Stats")
		float fSuper = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* HealthBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Health100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Health90;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Health80;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Health70;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Health60;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Health50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Health40;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Health30;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Health20;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Health10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* SuperBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Super100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Super90;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Super80;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Super70;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Super60;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Super50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Super40;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Super30;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Super20;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Arts")
		UTexture* Super10;


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
		uint8 iComboCount = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Stats")
		uint8 iKillCount = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player")
		ABSPlayer* CurPlayer;

	UGameManager* GameManager;
	FString HealthText;
	FString SuperText;
	FString ComboText;
	FString KillText;
};
