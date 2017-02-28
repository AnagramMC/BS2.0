// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BSPlayer.h"
#include "BasicEnemyMelee.h"


ABasicEnemyMelee::ABasicEnemyMelee()
{
	AttackCollider = CreateDefaultSubobject<USphereComponent>(TEXT("AttackCollider"));
	AttackCollider->AttachTo(RootComponent);

	DetectCollider = CreateDefaultSubobject<USphereComponent>(TEXT("DetectCollider"));
	DetectCollider->AttachTo(RootComponent);

}

void ABasicEnemyMelee::PerformMeleeAttack()
{
	TArray<AActor*> OverlappedActors;

	AttackCollider->GetOverlappingActors(OverlappedActors);

	for (AActor* Character : OverlappedActors)
	{
		ABSPlayer* Player = Cast<ABSPlayer>(Character);

		if (Player)
		{
			UGameplayStatics::ApplyDamage(Character, MeleeDamage, NULL, this, NULL);
		}
	}
}

uint16 ABasicEnemyMelee::EnemiesNearMe()
{
	//Look and store actors
	TArray<AActor*>Sphere;
	DetectCollider->GetOverlappingActors(Sphere);

	for (uint16 i = 0; i <= Sphere.Num()-1; i++)
	{
		AActor* const ActorContainer = Sphere[i];
		ABasicEnemyMelee* const MyComrade = Cast<ABasicEnemyMelee>(ActorContainer);

		if (MyComrade)
		{
			CurNumber++;
			
		}
	}
	ResultNumber = CurNumber;
	CurNumber = 0;
	return ResultNumber;
	
}

