// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "TEnemy.generated.h"

UCLASS()
class BATHROBESAMURAI_API ATEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Sphere collider that triggers interact */
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* Collider;

	// Function for player overlap.
	UFUNCTION()
	void OnPlayerOverlap(AActor* OverlappedPlayer, AActor* OtherActor);
	
};
