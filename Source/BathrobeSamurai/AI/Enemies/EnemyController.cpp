// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BSPlayer.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyController.h"


AEnemyController::AEnemyController(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));

	SetPerceptionComponent(*ObjectInitializer.CreateDefaultSubobject<UAIPerceptionComponent>(this, TEXT("Perception")));

	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));

	GetAIPerceptionComponent()->ConfigureSense(*Sight);
	GetAIPerceptionComponent()->SetDominantSense(Sight->GetSenseImplementation());

	GetAIPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &AEnemyController::UpdatePerception);
}

void AEnemyController::Possess(APawn* Pawn)
{
	if (Pawn)
	{
		PawnRef = Cast<AEnemy>(Pawn);

		if (PawnRef)
		{
			Brain = PawnRef->BehaviorComponent;
		}

		BlackboardComponent->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*BehaviorTree);

		if (BlackboardComponent)
		{

		}

	}
}

void AEnemyController::UpdatePerception(TArray<AActor*> SensedActor)
{

}

