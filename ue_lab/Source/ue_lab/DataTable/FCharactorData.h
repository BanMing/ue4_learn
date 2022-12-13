// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FCharactorData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct UE_LAB_API FCharactorData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	FCharactorData() :Name(""), HP(0), LP(0), Avator(nullptr) {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
		int32 HP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
		int32 LP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
		TSoftObjectPtr<UTexture> Avator;
};
