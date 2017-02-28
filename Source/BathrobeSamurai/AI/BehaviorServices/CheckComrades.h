// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "AI/Enemies/BasicEnemyMelee.h"
#include "AIController.h"
#include "CheckComrades.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API UCheckComrades : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
	
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

public:
	AAIController* Controller;

	ABasicEnemyMelee* ColliderReference;

	uint16 NumberEnemies;

	UBlackboardComponent* Blackboard;

};
