// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "GoToRandomPoint.h"


EBTNodeResult::Type UGoToRandomPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (!GetWorld())
	{
		return EBTNodeResult::Failed;
	}

	if (!Controller)
	{
		Controller = OwnerComp.GetAIOwner();

	}
	else
	{
		Origin = Controller->GetCharacter()->GetActorLocation();
		const float SearchRadius = 500.f;
		const FVector RandomLocation = UNavigationSystem::GetRandomReachablePointInRadius(Controller, Origin, SearchRadius);

		if (RandomLocation != FVector::ZeroVector)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(), RandomLocation);
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;


}



