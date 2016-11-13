// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "TestEnemyController.h"
#include "BSPlayer.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "TEnemy.h"


// Sets default values
ATEnemy::ATEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates a collider and attaches it to root component.
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Collider->AttachTo(RootComponent);

	// Attached ActorOveralp functionality to custom functions.
	OnActorBeginOverlap.AddDynamic(this, &ATEnemy::OnPlayerOverlap);
}

// Called when the game starts or when spawned
void ATEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATEnemy::OnPlayerOverlap(AActor* OverlappedPlayer, AActor* OtherActor)
{
	ABSPlayer* Player = Cast<ABSPlayer>(OtherActor);

	if (Player)
	{
		ATestEnemyController* Controller = Cast<ATestEnemyController>(GetController());

		Controller->BlackboardComponent->SetValue<UBlackboardKeyType_Object>(TEXT("Player"), Player);
	}
}

