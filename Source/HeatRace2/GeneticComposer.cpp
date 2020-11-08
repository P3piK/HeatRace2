// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneticComposer.h"
#include "GeneFormula.h"

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
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "debug msg");
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "debug msg");
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "debug msg");
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "debug msg");

	FVector Location(-5181.f, 11529.f, 20.f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;

	//SpawnActor<AStaticMeshActor>(Location, Rotation, SpawnInfo);
	AGeneFormula* gformula = GetWorld()->SpawnActor<AGeneFormula>(Location, Rotation, SpawnInfo);
	GetWorld()->SpawnActor<AGeneFormula>(Location, Rotation, SpawnInfo);
	GetWorld()->SpawnActor<AGeneFormula>(Location, Rotation, SpawnInfo);
	//GetWorld()->SpawnActor<AGeneFormula>(Location, Rotation, SpawnInfo);

	UE_LOG(LogTemp, Log, TEXT("Your message"));
	UE_LOG(LogTemp, Log, TEXT("Your message"));
	UE_LOG(LogTemp, Log, TEXT("Your message"));
}

