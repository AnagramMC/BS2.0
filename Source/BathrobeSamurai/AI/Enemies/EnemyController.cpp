// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BSPlayer.h"
#include "EnemyStorage.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "EnemyController.h"


AEnemyController::AEnemyController(const class FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
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
	Super::Possess(Pawn);

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

			BlackboardComponent->SetValue<UBlackboardKeyType_Object>(TEXT("SelfActor"), PawnRef);

			BlackboardComponent->SetValue<UBlackboardKeyType_Vector>(TEXT("StartLocation"), PawnRef->GetActorLocation());
			BlackboardComponent->SetValue<UBlackboardKeyType_Vector>(TEXT("TargetLocation"), PawnRef->GetActorLocation());
			BlackboardComponent->SetValue<UBlackboardKeyType_Vector>(TEXT("PlayerMemoryLocation"), PawnRef->GetActorLocation());

			if (Brain)
			{
				BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(TEXT("BehaviorType"), Brain->InitialBehavior);
				BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(TEXT("IdleType"), Brain->IdleType);
				BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(TEXT("PatrolType"), Brain->PatrolType);
				BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(TEXT("EngageType"), Brain->EngageType);

				BlackboardComponent->SetValue<UBlackboardKeyType_Float>(TEXT("WanderRange"), Brain->MaxRandLocationDistance);
				BlackboardComponent->SetValue<UBlackboardKeyType_Float>(TEXT("WanderWait"), Brain->RandLocationDelay);
				BlackboardComponent->SetValue<UBlackboardKeyType_Float>(TEXT("AttackDistance"), Brain->AttackDistance);

			}
		}

		Sight->SightRadius = PawnRef->SightRange;
		Sight->LoseSightRadius = PawnRef->LoseSightRange;
		Sight->PeripheralVisionAngleDegrees = PawnRef->SightAngle;
		Sight->DetectionByAffiliation.bDetectEnemies = true;
		Sight->DetectionByAffiliation.bDetectNeutrals = true;
		Sight->DetectionByAffiliation.bDetectFriendlies = true;

		GetAIPerceptionComponent()->ConfigureSense(*Sight);

		UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, Sight->GetSenseImplementation(), PawnRef);

	}
}

void AEnemyController::UpdatePerception(TArray<AActor*> SensedActor)
{
	for (AActor* Actor : SensedActor)
	{
		//UE_LOG(LogTemp, Warning, TEXT("I See!"));

		ABSPlayer* Player = Cast<ABSPlayer>(Actor);

		if (Player)
		{

			FActorPerceptionBlueprintInfo Info;

			GetAIPerceptionComponent()->GetActorsPerception(Actor, Info);

			if (Info.LastSensedStimuli.Num() > 0)
			{
				const FAIStimulus Stimulus = Info.LastSensedStimuli[0];

				if (Stimulus.WasSuccessfullySensed())
				{

					UE_LOG(LogTemp, Warning, TEXT("See Player!"));
				
					if (Brain->GetBehaviorConfig().OnSightTrigger)
					{

						Brain->ChangeBehavior(Brain->GetBehaviorConfig().OnSightBehaviorTo);

						//BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(TEXT("BehaviorType"), Brain->GetBehaviorConfig().BehaviorType);
						//BlackboardComponent->SetValue<UBlackboardKeyType_Object>(TEXT("TargetActor"), Player);

						if (Brain->GetBehaviorConfig().BehaviorType == ENGAGE)
						{
							TArray<AActor*> FoundActors;

							UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyStorage::StaticClass(), FoundActors);

							if (FoundActors.Num() > 0)
							{
								AEnemyStorage* EnemyStorage = Cast<AEnemyStorage>(FoundActors[0]);
								
								if (EnemyStorage)
								{
									EnemyStorage->AddEnemyToList(PawnRef);
								}
							}
						}
					}

					
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("Lost Player!"));

					if (Brain->GetBehaviorConfig().OnLoseSightTrigger)
					{
						Brain->ChangeBehavior(Brain->GetBehaviorConfig().OnLoseSightBehaviorTo);

						BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(TEXT("BehaviorType"), Brain->GetBehaviorConfig().BehaviorType);

						
					}

					BlackboardComponent->SetValue<UBlackboardKeyType_Vector>(TEXT("PlayerMemoryLocation"), Player->GetActorLocation());
					
				}
			}
		}
	}
}

