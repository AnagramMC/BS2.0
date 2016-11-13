// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"

#include "TestEnemyController.h"


ATestEnemyController::ATestEnemyController()
{
	// Creates both behavior tree and blackboard components.
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void ATestEnemyController::Possess(APawn* Pawn)
{
	Super::Possess(Pawn);

	if (Pawn)
	{
		BlackboardComponent->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*BehaviorTree);

		BlackboardComponent->SetValue<UBlackboardKeyType_Object>(TEXT("SelfActor"), Pawn);
	}
}

