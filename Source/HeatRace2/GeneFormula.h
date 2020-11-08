// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehicle.h"
#include "GeneFormula.generated.h"

UCLASS()
class HEATRACE2_API AGeneFormula : public AWheeledVehicle
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneFormula();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
