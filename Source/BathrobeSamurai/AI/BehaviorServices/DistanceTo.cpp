// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "DistanceTo.h"

void UDistanceTo::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	if (!Blackboard)
	{
		Blackboard = OwnerComp.GetBlackboardComponent();
	}

	else
	{
		if (!BasicController)
		{
			BasicController = Cast<AEnemyController>(Blackboard->GetOwner());
		}
		else
		{
			Player = Cast<ABSPlayer>(BasicController->GetBlackboardComp()->GetValueAsObject(TEXT("TargetActor")));

			if (Player)
			{
				FVector PlayerLocation = Player->GetActorLocation();
				APawn* TempPawn = BasicController->GetPawn();
				if (TempPawn)
				{
					FVector EnemyLocation = TempPawn->GetActorLocation();
					Distance = FVector::Dist(PlayerLocation, EnemyLocation);
					Blackboard->SetValueAsFloat(TEXT("TargetDistance"), Distance);
				}

			}
			else
			{
				GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Blue, TEXT("No player"));
				return;
			}
		}
	}

}


