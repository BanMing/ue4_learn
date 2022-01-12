// Fill out your copyright notice in the Description page of Project Settings.


#include "ue_lab/DataTable/CharactorDataTest.h"

// Sets default values
ACharactorDataTest::ACharactorDataTest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharactorDataTest::BeginPlay()
{
	Super::BeginPlay();
	static ConstructorHelpers::FObjectFinder<UDataTable> charactorData(TEXT("/Games/DataTable/Charactors.Charactors"));
	if (charactorData.Succeeded())
	{
		UE_LOG(LogAnimation, Log, TEXT("Successded"));
		//CharactorData = charactorData.Object;
	}
}

// Called every frame
void ACharactorDataTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

