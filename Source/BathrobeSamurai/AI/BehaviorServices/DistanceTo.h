// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "AI/Enemies/EnemyController.h"
#include "BSPlayer.h"
#include "DistanceTo.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API UDistanceTo : public UBTService_BlackboardBase
{
	GENERATED_BODY()
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	float Distance;

	UBlackboardComponent* Blackboard;

	AActor* Player;
	
	AEnemyController* BasicController;
	
};
