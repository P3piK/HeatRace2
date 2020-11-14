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

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
						AActor* OtherActor,
						UPrimitiveComponent* OtherComp,
						int32 OtherBodyIndex,
						bool bFromSweep,
						const FHitResult& SweepResult);

	UPROPERTY(Category = Path, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<float> Path;

	UPROPERTY(Category = Path, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TArray<float> FollowPath;

	UPROPERTY(Category = GeneticAlgorithm, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool isFreezed;

private:


};
