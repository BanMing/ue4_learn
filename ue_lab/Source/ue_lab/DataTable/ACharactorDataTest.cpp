// Fill out your copyright notice in the Description page of Project Settings.


#include "DataTable/ACharactorDataTest.h"

// Sets default values
ACharactorDataTest::ACharactorDataTest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//UE_LOG(LogPlayLevel, Log, TEXT("111111111111111111Successded!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));
	GLog->Log(TEXT("ssss"));
	CharactorData = LoadObject<UDataTable>(NULL, TEXT("DataTable'/Game/DataTable/Charactors.Charactors'"));
	CharactorData2 = LoadObject<UDataTable>(NULL, TEXT("DataTable'/Game/DataTable/Charactors.Charactors'"));
	UDataTable* charactorData = LoadObject<UDataTable>(NULL, TEXT("DataTable'/Game/DataTable/Charactors.Charactors'"));
	//static ConstructorHelpers::FObjectFinder<UDataTable> charactorData(TEXT("DataTable'/Game/DataTable/Charactors.Charactors'"));
	if (IsValid(CharactorData))
		//if (charactorData.Succeeded())
	{
		GLog->Log(TEXT("Successded!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));
		UE_LOG(LogInit, Log, TEXT("2222Successded!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));
		//GLog.Log(TEXT(""));
		//CharactorData = charactorData;
	}

}

// Called when the game starts or when spawned
void ACharactorDataTest::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACharactorDataTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

