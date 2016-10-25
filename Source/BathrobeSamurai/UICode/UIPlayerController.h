// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "BSPlayer.h"
#include "Blueprint/UserWidget.h"
#include "UIPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API AUIPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Reference UMG Asset in the Editor
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> wMainMenu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> wPauseMenu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> wDeathMenu;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> wLoadingScreen;

	bool bIsDead = false;
	
protected:
	// Variable to hold the widget After Creating it.
	UUserWidget* MyMainMenu;
	UUserWidget* MyPauseMenu;
	UUserWidget* MyDeathMenu;
	UUserWidget* MyLoadingScreen;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character|Stats")
		float Health = 1.f;

protected:
	// Override BeginPlay()
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	void PauseMenu();
	void MainMenu();

public:
	UFUNCTION(BlueprintCallable, Category = "WidgetCall")
		void DeathScreen();
	UFUNCTION(BlueprintCallable, Category = "WidgetCall")
		void LoadingScreen();
};
