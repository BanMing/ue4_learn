// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAS_LearnGameMode.h"
#include "GAS_LearnCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAS_LearnGameMode::AGAS_LearnGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
