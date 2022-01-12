// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "CharactorDataTest.generated.h"

UCLASS()
class UE_LAB_API ACharactorDataTest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACharactorDataTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	const UDataTable* CharactorData = nullptr;
};
