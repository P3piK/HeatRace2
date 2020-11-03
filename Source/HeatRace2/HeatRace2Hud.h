// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HeatRace2Hud.generated.h"

UCLASS(config = Game)
class AHeatRace2Hud : public AHUD
{
	GENERATED_BODY()

public:
	AHeatRace2Hud();

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface

};
