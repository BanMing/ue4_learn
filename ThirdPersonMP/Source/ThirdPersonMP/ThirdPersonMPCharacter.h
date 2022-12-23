// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "ThirdPersonMPCharacter.generated.h"

UCLASS(config = Game)
class AThirdPersonMPCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	AThirdPersonMPCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input)
	float TurnRateGamepad;

protected:
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

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	//
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	float MaxHealth;

	// The player`s current health. When reduced to 0, they are considered dead.
	UPROPERTY(ReplicatedUsing = OnRep_CurrentHealth)
	float CurrentHealth;

	// RepNotity for changes made to current health.
	UFUNCTION()
	void OnRep_CurrentHealth();

	// Response to health being updated.
	// Called on the server immediately after modification,
	// and on clients in response to a RepNotufy
	void OnHealthUpdate();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const
	{
		return CameraBoom;
	}
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const
	{
		return FollowCamera;
	}

public:
	// Property replication
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UFUNCTION(BlueprintPure, Category = "Health")
	FORCEINLINE float GetMaxHealth() const
	{
		return MaxHealth;
	}

	UFUNCTION(BlueprintPure, Category = "Health")
	FORCEINLINE float GetCurrentHealth() const
	{
		return CurrentHealth;
	}

	UFUNCTION(BlueprintCallable, Category = "Health")
	void SetCurrentHealth(float healthValue);

	UFUNCTION(BlueprintCallable, Category = "Health")
	float TakeDamage(float DamageTaken, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay|Projectile")
	TSubclassOf<class AThirdPersonMPProjectile> ProjectileClass;

	// Delay between shots in seconds. Used to control fire rate for your test projectile,
	// but also to prevent an overflow of server functions from binding SpawnProjectile directly to input
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	float FireRate;

	// If ture, you are in the process of firing projectiles
	bool bIsFiringWeapon;

	// FUnction for beginning weapon fire
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void StartFire();

	// Function for ending weapon fire. Once this is called, the player can use StartFire again
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void StopFire();

	// Server function for spawning projectiles
	UFUNCTION(Server, Reliable)
	void HandleFire();

	// A timer handle used for providing the fire the rate delay in-between spawns
	FTimerHandle FiringTimer;

public:
	// udmey course
	UFUNCTION(BlueprintCallable)
	void OpenLobby();

	UFUNCTION(BlueprintCallable)
	void CallOpenLevel(const FString& IPAddress);

	UFUNCTION(BlueprintCallable)
	void CallClientTravel(const FString& IPAddress);
};
