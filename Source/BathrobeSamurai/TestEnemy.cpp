// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "TestEnemy.h"


// Sets default values
ATestEnemy::ATestEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creates a root component for the actor.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	// Creates a mesh and attaches it to root component.
	Mesh = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->AttachTo(RootComponent);

	// Creates a collider and attaches it to root component.
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Collider->AttachTo(RootComponent);


	// Attached ActorOveralp functionality to custom functions.
	OnActorBeginOverlap.AddDynamic(this, &ATestEnemy::OnPlayerOverlap);

}

// Called when the game starts or when spawned
void ATestEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATestEnemy::OnPlayerOverlap(AActor* OverlappedPlayer, AActor* OtherActor)
{

}

