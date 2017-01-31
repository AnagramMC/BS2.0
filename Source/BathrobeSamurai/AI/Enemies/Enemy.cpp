// Fill out your copyright notice in the Description page of Project Settings.

#include "BathrobeSamurai.h"
#include "BSPlayer.h"
#include "EnemyController.h"
#include "EnemyStorage.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
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

	CurrentHealth = MaxHealth;
	
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABSPlayer::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		ABSPlayer* Player = Cast<ABSPlayer>(FoundActors[0]);

		if (Player)
		{
			AEnemyController* EnemyController = Cast<AEnemyController>(GetController());

			if (EnemyController)
			{
				EnemyController->BlackboardComponent->SetValue<UBlackboardKeyType_Object>(TEXT("TargetActor"), Player);
			}
		}
	}
}

// Called every frame
void AEnemy::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

float AEnemy::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	CurrentHealth -= ActualDamage;

	UE_LOG(LogTemp, Warning, TEXT("%f"), CurrentHealth);

	if (CurrentHealth <= 0)
	{
		OnDeath();
	}

	return ActualDamage;
}

void AEnemy::OnDeath()
{
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyStorage::StaticClass(), FoundActors);

	if (FoundActors.Num() > 0)
	{
		AEnemyStorage* EnemyStorage = Cast<AEnemyStorage>(FoundActors[0]);

		if (EnemyStorage)
		{
			EnemyStorage->RemoveEnemyFromList(this);
		}
	}

	Destroy();
}


