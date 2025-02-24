// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BSPlayer.generated.h"

// Enumerated values so we can keep track of what state the player is in to notify the Anim Blueprint on which animation to play
UENUM(BlueprintType)
enum class BodyState : uint8
{
	IDLE = 0,
	MOVING = 1,
	JUMP = 2,
	ATTACK = 3,
	BLOCK = 4,
	EVADE = 5,
	SUPER = 6,
	HIT = 7,
	DEATH = 8
};

//Enumerated values so we can keep track of what attack the player is in so we can notify the Anim Blueprint on which attack to play next
UENUM(BlueprintType)
enum class CurrentAttack : uint8
{
	DEFAULT = 0,
	ATTACK1 = 1,
	ATTACK2 = 2,
	ATTACK3 = 3,
	HATTACK1 = 4,
	HATTACK2 = 5,
	HATTACK3 = 6
};

UCLASS()
class BATHROBESAMURAI_API ABSPlayer : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* HitCollider;

public:
	// Sets default values for this character's properties
	ABSPlayer();

	// Tick function that runs every frame
	virtual void Tick(float DeltaSeconds) override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(EditDefaultsOnly, Category = Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(EditDefaultsOnly, Category = Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
	BodyState ArinBodyState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enum")
	CurrentAttack ArinCurAttack;

	UFUNCTION(BlueprintCallable, Category = "Effects")
	void HitEffects();


public:

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	/** Manages the lockon state - will be a toggle on and off */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool LockOnEnemy;

	//Counter for what light attack arin should be on.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int LightAttackCounter;

	//Counter for what heavy attack arin should be on.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int HeavyAttackCounter;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool AppliedDamage;

};
