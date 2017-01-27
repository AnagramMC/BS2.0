// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
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

	// ...
	
}

FBasicBehaviors UBehaviorComponent::GetBehaviorConfig()
{
	return CurrentBehaviorConfig;
}

void UBehaviorComponent::ChangeBehavior(TEnumAsByte<EBehaviorTypes> NewBehavior)
{

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


