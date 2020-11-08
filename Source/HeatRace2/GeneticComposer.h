// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeneFormula.h"
#include "GeneticComposer.generated.h"

UCLASS()
class HEATRACE2_API AGeneticComposer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGeneticComposer();

	UPROPERTY(Category = CarComponent, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	AGeneFormula* Formula;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
