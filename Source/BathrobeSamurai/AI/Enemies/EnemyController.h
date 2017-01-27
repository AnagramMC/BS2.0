// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Enemy.h"
#include "BehaviorComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API AEnemyController : public AAIController
{
	GENERATED_BODY()

public:

	AEnemyController(const class FObjectInitializer& ObjectInitializer);

	virtual void Possess(APawn* Pawn);

	AEnemy* PawnRef;

	UPROPERTY(EditDefaultsOnly)
	UBehaviorTree* BehaviorTree;

	UPROPERTY(EditDefaultsOnly)
	UBehaviorComponent* BehaviorTreeComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UBlackboardComponent* BlackboardComponent;

	UAISenseConfig_Sight* Sight;

	UFUNCTION()
	void UpdatePerception(TArray<AActor*> SensedActor);

	
};
