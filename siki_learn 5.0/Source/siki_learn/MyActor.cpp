// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	InitLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrign = FVector(0.0f);
	TickLocaltionOffset = FVector(0.0f);
	IsInitLocation = false;
	IsShouldMove = false;

	InitFoce = FVector(0.0f);
	InitTorque = FVector(0.0f);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	PlacedLocation = GetActorLocation();
	if (IsInitLocation)
	{
		SetActorLocation(InitLocation);
	}

	//MyStaticMesh->AddForce(InitFoce, NAME_None, true);
	//MyStaticMesh->AddTorque(InitTorque, NAME_None, true);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsShouldMove)
	{
		AddActorLocalOffset(TickLocaltionOffset,true);
	}
}

