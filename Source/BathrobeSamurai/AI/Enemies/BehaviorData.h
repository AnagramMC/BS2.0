// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BehaviorData.generated.h"

///////////////////////////////////////////////ENUMS///////////////////////////////////////////////////////////////////
UENUM(BlueprintType)
enum EBehaviorTypes
{
	IDLE							UMETA(DisplayName = "Idle"),
	PATROL							UMETA(DispalyName = "Patrol"),
	ENGAGE							UMETA(DisplayName = "Engage"),
	HIT								UMETA(DisplayName = "Hit"),
	FLEE							UMETA(DisplayName = "Flee")
};

UENUM(BlueprintType)
enum EIdleTypes
{
	STATIONARY						UMETA(DisplayName = "Stationary"),
	WANDER							UMETA(DisplayName = "Wander")
};

UENUM(BlueprintType)
enum EPatrolTypes
{
	SINGLE							UMETA(DisplayName = "Single"),
	LOOPING							UMETA(DisplayName = "Looping"),
	BACKANDFORTH					UMETA(DisplayName = "Back And Forth")
};

UENUM(BlueprintType)
enum EEngageType
{
	ATTACKING						UMETA(DisplayName = "Attacking"),
	STALKING						UMETA(DisplayName = "Stalking")
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////STRUCTURES/////////////////////////////////////////////////////////////////

USTRUCT(BlueprintType)
struct FActorTrigger
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorTrigger")
	FName ActorTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorTrigger")
	TEnumAsByte<EBehaviorTypes> BehaviorTo;
};

USTRUCT(BlueprintType)
struct FBasicBehaviors
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicBehavior")
	TEnumAsByte<EBehaviorTypes> BehaviorType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicBehavior")
	float MovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicBehavior")
	TArray<FName> TargetTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicBehavior")
	TArray<FActorTrigger> OnSightTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicBehavior")
	TArray<FActorTrigger> OnLoseSightTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicBehavior")
	TArray<UAnimMontage*> Animations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicBehavior")
	bool RandomAnim;
};

