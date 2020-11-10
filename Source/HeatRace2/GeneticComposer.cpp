// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneticComposer.h"
#include "GeneFormula.h"
#include "WheeledVehicleMovementComponent4W.h"

// Sets default values
AGeneticComposer::AGeneticComposer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGeneticComposer::BeginPlay()
{
	Super::BeginPlay();
	
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "debug msg");

	FVector Location(-5181.f, 11529.f, 20.f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	Rotation.Yaw = 90.f;
	FActorSpawnParameters SpawnInfo;

	const int populationSize = 5;

	AGeneFormula* sample[populationSize];
	
	for (int i = 0; i < populationSize; i++)
	{
		sample[i] = GetWorld()->SpawnActor<AGeneFormula>(Location, Rotation, SpawnInfo);
		sample[i]->GetVehicleMovementComponent()->SetThrottleInput(FMath::RandRange(.5f, 1.f));
	}



	UE_LOG(LogTemp, Log, TEXT("Your message"));
	UE_LOG(LogTemp, Log, TEXT("Your message"));
	UE_LOG(LogTemp, Log, TEXT("Your message"));
}

