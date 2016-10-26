// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "GameManager.h"

UGameManager::UGameManager()
{
	TerraBugsTotal = 3;
	TerraBugsKilled = 0;
	BugsKilled = 0;
	CurrentCombo = 0;
}

UGameManager::UGameManager(int32 _TerraBugsTotal)
{
	TerraBugsTotal = _TerraBugsTotal;
	TerraBugsKilled = 0;
	BugsKilled = 0;
	CurrentCombo = 0;
}

//uint8 UGameManager::GetComboCount()
//{
//	ABSPlayer* Player = Cast<ABSPlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
//	if (Arin)
//		return Player->getComboCounter();
//	else
//		return NULL;
//}

void UGameManager::TerraBugKilled()
{
	TerraBugsKilled += 1;
	if (TerraBugsKilled >= TerraBugsTotal)
	{
		Victory();
	}
}

void UGameManager::Victory()
{

}