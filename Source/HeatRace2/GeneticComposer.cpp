// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneticComposer.h"
#include "GeneFormula.h"
#include "WheeledVehicleMovementComponent4W.h"

// Sets default values
AGeneticComposer::AGeneticComposer()
{
	PrimaryActorTick.bCanEverTick = true; 
	//PrimaryActorTick.bStartWithTickEnabled = true;
	//SetActorTickEnabled(true);
	
	SetActorTickInterval(1.f);
	Population = new AGeneFormula*[PopulationSize];
}

// Called when the game starts or when spawned
void AGeneticComposer::BeginPlay()
{
	Super::BeginPlay();
	
	// Debug Message
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "debug msg");

	// Generate first population
	PrepareOffspring();
	GeneratePopulation();


	// Debug message
	UE_LOG(LogTemp, Log, TEXT("Your message"));
	UE_LOG(LogTemp, Log, TEXT("Your message"));
	UE_LOG(LogTemp, Log, TEXT("Your message"));
}

void AGeneticComposer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Log, TEXT("tick"));

	if (AllCartsDisabled())
	{
		// Next generation
		PrepareFitness();
		PrepareOffspring();

		// Mutation

		ResetPopulation();
		GeneratePopulation();	// TODO: Generate offspring carts
	}

}

void AGeneticComposer::GeneratePopulation()
{
	FVector Location(-5181.f, 11529.f, 20.f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	Rotation.Yaw = 90.f;
	FActorSpawnParameters SpawnInfo;

	for (int i = 0; i < PopulationSize; i++)
	{
		Population[i] = GetWorld()->SpawnActor<AGeneFormula>(Location, Rotation, SpawnInfo);
		Population[i]->FollowPath = (*Offsprings)[i]->Path;
	}
}

void AGeneticComposer::ResetPopulation()
{
	for (int i = 0; i < PopulationSize; i++)
	{
		Population[i]->Destroy();
	}
}

void AGeneticComposer::PrepareFitness()
{

}

void AGeneticComposer::PrepareOffspring()
{
	Offsprings = new TArray<Chromosome*>();

	for (int i = 0; i < PopulationSize; i++)
	{
		TArray<Chromosome*>* parents = FindParents();
		Chromosome* offspring = Crossover(parents);

		Offsprings->Add(offspring);
	}
}

TArray<Chromosome*>* AGeneticComposer::FindParents()
{
	TArray<Chromosome*>* ret = new TArray<Chromosome*>();
	float rand1 = FMath::RandRange(0, 1);
	float rand2 = FMath::RandRange(0, 1);
	Chromosome* parent1;
	Chromosome* parent2;

	// TODO:
	// 

	ret->Add(parent1);
	ret->Add(parent2);

	return ret;
}

Chromosome* AGeneticComposer::Crossover(TArray<Chromosome*>* parents)
{
	Chromosome* offspring = new Chromosome();

	// TODO:
	// 
	
	return offspring;
}

bool AGeneticComposer::AllCartsDisabled()
{
	bool ret = true;

	for (int i = 0; i < PopulationSize; i++)
	{
		if (!Population[i]->isFreezed)
		{
			ret = false;
			break;
		}
	}

	return ret;
}
