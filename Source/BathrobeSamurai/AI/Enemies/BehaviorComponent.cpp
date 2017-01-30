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

	IdleBehaviorConfig.BehaviorType = IDLE;
	PatrolBehaviorConfig.BehaviorType = PATROL;
	EngageBehaviorConfig.BehaviorType = ENGAGE;
	HitBehaviorConfig.BehaviorType = HIT;
	FleeBehaviorConfig.BehaviorType = FLEE;

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

	AnimationIndex.AddZeroed(BehaviorArray.Num());

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

	PawnRef->GetCharacterMovement()->MaxWalkSpeed = GetBehaviorConfig().MovementSpeed;

	if (ControllerRef)
	{

	}
}

void UBehaviorComponent::FindNextPatrolLocation()
{

}

float UBehaviorComponent::PlayAnimation()
{
	UAnimMontage* Anim;

	int Order;

	if (CurrentBehaviorConfig.Animations.Num() > 0)
	{
		if (CurrentBehaviorConfig.RandomAnim)
		{
			Order = FMath::RandRange(0, CurrentBehaviorConfig.Animations.Num() - 1);

			Anim = CurrentBehaviorConfig.Animations[Order];
		}
		else
		{
			uint8 Bytes = InitialBehavior;

			AnimationIndex[Bytes] ++;

			Order = AnimationIndex[Bytes] % CurrentBehaviorConfig.Animations.Num();

			if (Order < 0)
			{
				Order = CurrentBehaviorConfig.Animations.Num() - 1;
			}

			Anim = CurrentBehaviorConfig.Animations[Order];
		}

		if (Anim)
		{
			return PawnRef->PlayAnimMontage(Anim);
		}
	}

	return 0.0f;
}


