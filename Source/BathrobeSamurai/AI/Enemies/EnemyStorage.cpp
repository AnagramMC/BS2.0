// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "EnemyController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "EnemyStorage.h"


// Sets default values
AEnemyStorage::AEnemyStorage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyStorage::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyStorage::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AEnemyStorage::AddEnemyToList(AEnemy* EnemyRef)
{
	if (!EnemyList.Contains(EnemyRef))
	{
		EnemyList.Add(EnemyRef);
	}

	ArrangeList();
}

void AEnemyStorage::ArrangeList()
{
	if (EnemyList.Num() > 0)
	{
		for (int i = 0; i < 4 && i < EnemyList.Num(); i++)
		{
			EnemyList[i]->BehaviorComponent->EngageType = ATTACKING;
			
			AEnemyController* EnemyController = Cast<AEnemyController>(EnemyList[i]->GetController());
			
			if (EnemyController)
			{
				EnemyController->BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(TEXT("EngageType"), EnemyList[i]->BehaviorComponent->EngageType);
			}
		}

		for (int i = 4; i < EnemyList.Num(); i++)
		{
			EnemyList[i]->BehaviorComponent->EngageType = STALKING;

			AEnemyController* EnemyController = Cast<AEnemyController>(EnemyList[i]->GetController());

			if (EnemyController)
			{
				EnemyController->BlackboardComponent->SetValue<UBlackboardKeyType_Enum>(TEXT("EngageType"), EnemyList[i]->BehaviorComponent->EngageType);
			}
		}
	}
}
