// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FP_FirstPersonGameMode.h"
#include "FP_FirstPersonHUD.h"
#include "Player/FirstPersonPlayer.h"
#include "UObject/ConstructorHelpers.h"

AFP_FirstPersonGameMode::AFP_FirstPersonGameMode()
{
	// Set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Player/Behaviour/BP_FirstPersonPlayer"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// Use our custom HUD class
	HUDClass = AFP_FirstPersonHUD::StaticClass();
}
