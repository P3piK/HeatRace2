// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameMode.h"
#include "GeneFormula.h"

AMyGameMode::AMyGameMode()
{

}

void AMyGameMode::BeginPlay()
{
	Super::BeginPlay();

	FVector location = FVector(-5222.f, 11495.f, 0.f);
	GetWorld()->SpawnActor(AGeneFormula::StaticClass(), &location);
}

