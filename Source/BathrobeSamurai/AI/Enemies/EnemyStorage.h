// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Enemy.h"
#include "EnemyStorage.generated.h"

UCLASS()
class BATHROBESAMURAI_API AEnemyStorage : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyStorage();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "EnemyList")
	void AddEnemyToList(AEnemy* EnemyRef);

	void RemoveEnemyFromList(AEnemy* EnemyRef);

	UPROPERTY(BlueprintReadWrite)
	TArray<AEnemy*> EnemyList;

	void ArrangeList();
	
};
