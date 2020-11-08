// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "GeneFormula.h"

void AMyGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FVector location = FVector(-5222.f, 11495.f, 0.f);
	GetWorld()->SpawnActor(AGeneFormula::StaticClass(), &location);
}
