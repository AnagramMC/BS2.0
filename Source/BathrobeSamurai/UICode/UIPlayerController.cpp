// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "UIPlayerController.h"

void AUIPlayerController::BeginPlay()
{
	Super::BeginPlay();

	AUIPlayerController::MainMenu();
}

void AUIPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*TActorIterator<ABSPlayer> Player = TActorIterator<ABSPlayer>(GetWorld());
	if (Player)
	{
		ABSPlayer* CurPlayer = Cast<ABSPlayer>(*Player);
		if (CurPlayer)
		{
			Health = CurPlayer->getHitPoints();

			if (CurPlayer->getIsDead() && !bIsDead)
			{
				AUIPlayerController::DeathScreen();
				SetPause(true);
			}
		}
	}*/

	//for testing purposes
	/*if (APlayerController::WasInputKeyJustPressed(EKeys::K))
	{
		AUIPlayerController::DeathScreen();
		SetPause(true);
	}*/

	if (GameManagerClass)
	{
		GameManager = NewObject<UGameManager>(this, GameManagerClass, TEXT("GameManager"));
		if (GameManager)
		{
			if (GameManager->GetDead())
			{
				AUIPlayerController::DeathScreen();
				SetPause(true);
			}
		}
	}

	if (APlayerController::WasInputKeyJustPressed(EKeys::P) || APlayerController::WasInputKeyJustPressed(EKeys::Gamepad_Special_Right))
	{
		AUIPlayerController::PauseMenu();
		SetPause(true);
	}
}

void AUIPlayerController::PauseMenu()
{
	if (wPauseMenu)
	{
		MyPauseMenu = CreateWidget<UUserWidget>(this, wPauseMenu);

		if (MyPauseMenu)
		{
			MyPauseMenu->AddToViewport(0);
			FInputModeUIOnly Mode;
			Mode.SetWidgetToFocus(MyPauseMenu->GetCachedWidget());
			SetInputMode(Mode);
		}

		bShowMouseCursor = true;
	}
}

void AUIPlayerController::MainMenu()
{
	if (wMainMenu) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		MyMainMenu = CreateWidget<UUserWidget>(this, wMainMenu);

		// now you can use the widget directly since you have a referance for it.
		// Extra check to  make sure the pointer holds the widget.
		if (MyMainMenu)
		{
			//let add it to the view port
			MyMainMenu->AddToViewport();
			FInputModeUIOnly Mode;
			Mode.SetWidgetToFocus(MyMainMenu->GetCachedWidget());
			SetInputMode(Mode);
		}

		//Show the Cursor.
		bShowMouseCursor = true;
	}

	MyMainMenu->RemoveFromViewport();
	MyMainMenu = nullptr;
	FInputModeGameOnly GameMode;
	SetInputMode(GameMode);
	FSlateApplication::Get().SetAllUserFocusToGameViewport();

	//Show the Cursor.
	bShowMouseCursor = false;
}

void AUIPlayerController::DeathScreen()
{
	if (wDeathMenu) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		MyDeathMenu = CreateWidget<UUserWidget>(this, wDeathMenu);

		// now you can use the widget directly since you have a referance for it.
		// Extra check to  make sure the pointer holds the widget.
		if (MyDeathMenu)
		{
			//let add it to the view port
			MyDeathMenu->AddToViewport();
			FInputModeUIOnly Mode;
			Mode.SetWidgetToFocus(MyDeathMenu->GetCachedWidget());
			SetInputMode(Mode);
		}

		//Show the Cursor.
		bShowMouseCursor = true;
		bIsDead = true;
	}
}

void AUIPlayerController::LoadingScreen()
{
	if (wLoadingScreen) // Check if the Asset is assigned in the blueprint.
	{
		// Create the widget and store it.
		MyLoadingScreen = CreateWidget<UUserWidget>(this, wLoadingScreen);

		// now you can use the widget directly since you have a referance for it.
		// Extra check to  make sure the pointer holds the widget.
		if (MyLoadingScreen)
		{
			//let add it to the view port
			MyLoadingScreen->AddToViewport();
			FInputModeUIOnly Mode;
			Mode.SetWidgetToFocus(MyLoadingScreen->GetCachedWidget());
			SetInputMode(Mode);
		}
	}
}