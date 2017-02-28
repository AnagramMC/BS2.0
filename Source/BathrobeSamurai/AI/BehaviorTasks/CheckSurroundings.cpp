// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "CheckSurroundings.h"

EBTNodeResult::Type UCheckSurroundings::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	if (!Controller)
	{
		Controller = OwnerComp.GetAIOwner();
		ColliderReference = Cast<ABasicEnemyMelee>(Controller->GetCharacter());
	}

	if (ColliderReference)
	{
		NumberEnemies = ColliderReference->EnemiesNearMe();
		OwnerComp.GetBlackboardComponent()->SetValueAsInt(TEXT("ComradesNear"), NumberEnemies);
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}


}
