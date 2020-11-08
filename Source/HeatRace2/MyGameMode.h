// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class HEATRACE2_API AMyGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyGameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
