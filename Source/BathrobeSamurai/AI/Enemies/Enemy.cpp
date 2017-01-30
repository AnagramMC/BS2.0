// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "Enemy.h"


// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BehaviorComponent = CreateDefaultSubobject<UBehaviorComponent>(TEXT("Behavior Component"));

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetCharacterMovement()->MaxWalkSpeed = BehaviorComponent->GetBehaviorConfig().MovementSpeed;

	
	
}

// Called every frame
void AEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


