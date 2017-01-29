// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "Enemy.h"
#include "EnemyController.h"
#include "BehaviorComponent.h"


// Sets default values for this component's properties
UBehaviorComponent::UBehaviorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBehaviorComponent::BeginPlay()
{
	Super::BeginPlay();

	PawnRef = Cast<AEnemy>(GetOwner());

	if (PawnRef)
	{
		ControllerRef = Cast <AEnemyController>(PawnRef->GetController());
	}


	BehaviorArray.Add(IdleBehaviorConfig);
	BehaviorArray.Add(PatrolBehaviorConfig);
	BehaviorArray.Add(EngageBehaviorConfig);
	BehaviorArray.Add(HitBehaviorConfig);
	BehaviorArray.Add(FleeBehaviorConfig);

	uint8 Bytes = InitialBehavior;

	CurrentBehaviorConfig = BehaviorArray[Bytes];

	
}

FBasicBehaviors UBehaviorComponent::GetBehaviorConfig()
{
	return CurrentBehaviorConfig;
}

void UBehaviorComponent::ChangeBehavior(TEnumAsByte<EBehaviorTypes> NewBehavior)
{
	uint8 Bytes = NewBehavior;

	CurrentBehaviorConfig = BehaviorArray[Bytes];

	if (ControllerRef)
	{

	}
}

void UBehaviorComponent::FindNextPatrolLocation()
{

}

void UBehaviorComponent::FindAttackTarget()
{

}

void UBehaviorComponent::PlayAnimation()
{

}


