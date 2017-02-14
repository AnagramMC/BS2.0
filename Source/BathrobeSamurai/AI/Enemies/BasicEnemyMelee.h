// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI/Enemies/Enemy.h"
#include "BasicEnemyMelee.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API ABasicEnemyMelee : public AEnemy
{
	GENERATED_BODY()
	
	
public:

	ABasicEnemyMelee();

	UPROPERTY(VisibleAnywhere)
	USphereComponent* AttackCollider;

	UFUNCTION(BlueprintCallable, Category = "Melee Attack")
	void PerformMeleeAttack();

	UPROPERTY(EditDefaultsOnly)
	float MeleeDamage;
	
};
