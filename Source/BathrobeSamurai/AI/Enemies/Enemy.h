// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BehaviorComponent.h"
#include "Enemy.generated.h"

UCLASS()
class BATHROBESAMURAI_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(VisibleAnywhere)
	UBehaviorComponent* BehaviorComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth;

	UPROPERTY(BlueprintReadWrite)
	float CurrentHealth;

	UPROPERTY(EditAnywhere, Category = "Sight")
	float SightRange;

	UPROPERTY(EditAnywhere, Category = "Sight")
	float LoseSightRange;

	UPROPERTY(EditAnywhere, Category = "Sight")
	float SightAngle;

	virtual float TakeDamage (float DamageAmount, struct FDamageEvent const & DamageEvent, class AController* EventInstigator, AActor* DamageCauser);


	void OnDeath();

};
