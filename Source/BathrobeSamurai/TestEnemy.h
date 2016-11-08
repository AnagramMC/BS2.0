// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "TestEnemy.generated.h"

UCLASS()
class BATHROBESAMURAI_API ATestEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATestEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/** Sphere collider that triggers interact */
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* Collider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SkeletalMesh)
	class USkeletalMeshComponent* Mesh;

	// Function for player overlap.
	UFUNCTION()
	void OnPlayerOverlap(AActor* OverlappedPlayer, AActor* OtherActor);

	
	
};
