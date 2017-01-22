// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "GameManager.h"

UGameManager::UGameManager()
{
	TerraBugsTotal = 3;
	TerraBugsKilled = 0;
	BugsKilledTotal = 0;
	KillStreak = 0;
	CurrentCombo = 0;
}

UGameManager::UGameManager(int32 _TerraBugsTotal)
{
	TerraBugsTotal = _TerraBugsTotal;
	TerraBugsKilled = 0;
	BugsKilledTotal = 0;
	KillStreak = 0;
	CurrentCombo = 0;
}

void UGameManager::SetComboCount()
{
	
}

void UGameManager::SetKillStreak()
{
	
}

uint8 UGameManager::GetComboCount()
{
	return CurrentCombo;
//	ABSPlayer* Player = Cast<ABSPlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
//	if (Player)
//		return Player->getComboCounter();
}

uint8 UGameManager::GetKillStreak()
{
	return KillStreak;
}

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

void UGameManager::SetDead(bool dead)
{
	bIsDead = dead;
}

bool UGameManager::GetDead()
{
	return bIsDead;
}