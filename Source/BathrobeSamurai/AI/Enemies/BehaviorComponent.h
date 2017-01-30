// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "BehaviorData.h"
#include "PatrolRoute.h"
#include "BehaviorComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATHROBESAMURAI_API UBehaviorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBehaviorComponent();

	// Called when the game starts
	virtual void BeginPlay() override;

private:

	FBasicBehaviors CurrentBehaviorConfig;

	TArray<FBasicBehaviors> BehaviorArray;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General Settings")
	TEnumAsByte<EBehaviorTypes> InitialBehavior;

	TArray<int> AnimationIndex;

	class AEnemy* PawnRef;

	class AEnemyController* ControllerRef;


////////////////////////////////////////////////////**IDLE**///////////////////////////////////////////////////////////////////////////

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Idle Settings")
	FBasicBehaviors IdleBehaviorConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Idle Settings")
	TEnumAsByte<EIdleTypes> IdleType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Idle Settings")
	float MaxRandLocationDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Idle Settings")
	float RandLocationDelay;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////**PATROL**///////////////////////////////////////////////////////////////////////////

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrol Settings")
	FBasicBehaviors PatrolBehaviorConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrol Settings")
	TEnumAsByte<EPatrolTypes> PatrolType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrol Settings")
	APatrolRoute* PatrolRoute;

	int PatrolSplineIndex;

	bool PatrolDirect;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////**ENGAGE**////////////////////////////////////////////////////////////////////////////

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Engage Settings")
	FBasicBehaviors EngageBehaviorConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Engage Settings")
	TEnumAsByte<EEngageTypes> EngageType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Engage Settings")
	float AttackDistance;

	AActor* AttackTarget;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////**HIT**///////////////////////////////////////////////////////////////////////////

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hit Settings")
	FBasicBehaviors HitBehaviorConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hit Settings")
	TEnumAsByte<EBehaviorTypes> HitTransition;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////**FLEE**/////////////////////////////////////////////////////////////////////////////

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flee Settings")
	FBasicBehaviors FleeBehaviorConfig;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////**Functions**//////////////////////////////////////////////////////////////////////////

public:

	FBasicBehaviors GetBehaviorConfig();

	void ChangeBehavior(TEnumAsByte<EBehaviorTypes> NewBehavior);

	void FindNextPatrolLocation();

	UFUNCTION(BlueprintCallable, Category = "Animation")
	float PlayAnimation();

};
