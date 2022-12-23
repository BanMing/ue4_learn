// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Abilities/GameplayAbility.h"
#include "CoreMinimal.h"
#include "GAS_Learn.h"

#include "GASGameplayAbility.generated.h"

/**
 *
 */
UCLASS()
class GAS_LEARN_API UGASGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UGASGameplayAbility();

	// Ability with this set will automatically activate when the input is pressed
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Ability")
	EGASAbilityInputID AbilityInputID = EGASAbilityInputID::None;
};
