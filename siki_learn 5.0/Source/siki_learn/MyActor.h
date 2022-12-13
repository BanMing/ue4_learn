// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class SIKI_LEARN_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();

	UPROPERTY(VisibleAnywhere, Category = "My Actor Components")
		UStaticMeshComponent* MyStaticMesh;

	UPROPERTY(EditInstanceOnly, Category = "My Actor Properties | Vector")
		FVector InitLocation;

	UPROPERTY(VisibleInstanceOnly, Category = "My Actor Properties | Vector")
		FVector PlacedLocation;

	UPROPERTY(EditDefaultsOnly, Category = "My Actor Properties | Vector")
		bool IsInitLocation;

	UPROPERTY(VisibleDefaultsOnly, Category = "My Actor Properties | Vector")
		FVector WorldOrign;

	UPROPERTY(EditAnywhere, Category = "My Actor Properties | Vector", meta = (ClampMin = -5.0f, ClampMax = 5.0f, UIMin = -5.0f, UIMax = 5.0f))
		FVector TickLocaltionOffset;

	UPROPERTY(EditAnywhere, Category = "My Actor Properties | Vector")
		bool IsShouldMove;

	UPROPERTY(EditInstanceOnly, Category = "My Actor Properties | Physic")
		FVector InitFoce;

	UPROPERTY(EditInstanceOnly, Category = "My Actor Properties | Physic")
		FVector InitTorque;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
