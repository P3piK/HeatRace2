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

	// Logic
	GeneratePopulation();


	// Debug message
	UE_LOG(LogTemp, Log, TEXT("Your message"));
	UE_LOG(LogTemp, Log, TEXT("Your message"));
	UE_LOG(LogTemp, Log, TEXT("Your message"));
}

void AGeneticComposer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (AllCartsDisabled())
	{
		// Next generation

		// save paths
		// further logic
		RemovePopulation();
		GeneratePopulation();
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
	}
}

void AGeneticComposer::RemovePopulation()
{
	for (int i = 0; i < PopulationSize; i++)
	{
		Population[i]->Destroy();
	}
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
