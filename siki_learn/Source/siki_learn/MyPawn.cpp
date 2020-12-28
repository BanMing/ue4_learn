// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h" 
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMyPawn::AMyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("CreateDefaultSubobject"));

	MyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyStaticMesh"));
	MyStaticMesh->SetupAttachment(GetRootComponent());

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("Texture2D'/Engine/StarterContent/Textures/T_ground_Moss_D.T_ground_Moss_D'"));
	if (StaticMeshAsset.Succeeded() && MaterialAsset.Succeeded())
	{
		MyStaticMesh->SetStaticMesh(StaticMeshAsset.Object);
		MyStaticMesh->SetMaterial(0, MaterialAsset.Object);
		MyStaticMesh->SetWorldScale3D(FVector::OneVector / 2);
	}

	MyCameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("MyCameraArm"));
	MyCameraArm->SetupAttachment(GetRootComponent());
	//MyCameraArm->relativeRotation = FVector(-45.f, 0.f, 0.f);
	MyCameraArm->TargetArmLength = 400.f;
	MyCameraArm->bEnableCameraLag = true;
	MyCameraArm->CameraLagSpeed = 30;

	MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MYCAMERA"));
	MyCamera->SetupAttachment(MyCameraArm);
	/*
		MyCamera->SetRelativeLocation(FVector(-300.f, 0.f, 300.f));
		MyCamera->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));*/

	AutoPossessPlayer = EAutoReceiveInput::Player0;
	MoveSpeed = 1;
	Velocity = FVector::ZeroVector;
	Roator = FVector::ZeroVector;

	bUseControllerRotationPitch = true;
	bUseControllerRotationYaw = true;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalOffset(Velocity*DeltaTime, true);

	AddControllerYawInput(Roator.Z);
	AddControllerPitchInput(Roator.Y);
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyPawn::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyPawn::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyPawn::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AMyPawn::LookRight);

}

void AMyPawn::MoveForward(float value)
{
	Velocity.X = FMath::Clamp(value, -1.f, 1.f)*MoveSpeed;
}

void AMyPawn::MoveRight(float value)
{
	Velocity.Y = FMath::Clamp(value, -1.f, 1.f)*MoveSpeed;
}

void AMyPawn::LookUp(float value)
{
	Roator.Y = FMath::Clamp(value, -100.f, 100.f);
}

void AMyPawn::LookRight(float value)
{
	Roator.Z = value;
}


