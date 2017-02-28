// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "CheckComrades.h"

void UCheckComrades::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	if (!Blackboard)
	{
		Blackboard = OwnerComp.GetBlackboardComponent();
	}

	if (!Controller)
	{
		Controller = OwnerComp.GetAIOwner();
		ColliderReference = Cast<ABasicEnemyMelee>(Controller->GetCharacter());
	}

	if (ColliderReference)
	{
		NumberEnemies = ColliderReference->EnemiesNearMe();
		Blackboard ->SetValueAsInt(TEXT("ComradesNear"), NumberEnemies);
		return;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Blue, TEXT("No colliderRef"));
		return;
	}
}
