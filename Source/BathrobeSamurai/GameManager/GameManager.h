// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "BSPlayer.h"
#include "TEnemy.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API UGameManager : public UObject
{
	GENERATED_BODY()

public:
	UGameManager();
	UGameManager(int32 _TerraBugsTotal);

	uint8 GetComboCount();
	uint8 GetKillStreak();

	void SetDead(bool dead);
	bool GetDead();

	void TerraBugKilled();
	void Victory();

private:
	int32 TerraBugsTotal;
	int32 TerraBugsKilled;
	int32 BugsKilledTotal;
	int32 KillStreak;
	uint8 CurrentCombo;
	bool bIsDead = false;

	void SetComboCount();
	void SetKillStreak();
};
