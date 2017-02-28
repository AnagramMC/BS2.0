// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "AI/Enemies/BasicEnemyMelee.h"
#include "AIController.h"
#include "CheckSurroundings.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API UCheckSurroundings : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;

public:
	AAIController* Controller;
	
	ABasicEnemyMelee* ColliderReference;
	
	uint16 NumberEnemies;

};
