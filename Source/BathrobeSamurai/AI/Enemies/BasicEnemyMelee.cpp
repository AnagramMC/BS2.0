// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BSPlayer.h"
#include "BasicEnemyMelee.h"


ABasicEnemyMelee::ABasicEnemyMelee()
{
	AttackCollider = CreateDefaultSubobject<USphereComponent>(TEXT("AttackCollider"));
	AttackCollider->AttachTo(RootComponent);

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

