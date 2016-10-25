// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TestEnemyController.generated.h"

/**
 * 
 */
UCLASS()
class BATHROBESAMURAI_API ATestEnemyController : public AAIController
{
	GENERATED_BODY()
	
public:

	ATestEnemyController();

	/** Reference to the behavior tree */
	UPROPERTY(EditDefaultsOnly)
		UBehaviorTree* BehaviorTree;

	/** Behavior tree components*/
	UPROPERTY(EditDefaultsOnly)
		UBehaviorTreeComponent* BehaviorTreeComponent;

	/** Blackboard components */
	UPROPERTY(EditDefaultsOnly)
		UBlackboardComponent* BlackboardComponent;

	// Function for the controlled pawn.
	void Possess(APawn* Pawn);
	
	
};
