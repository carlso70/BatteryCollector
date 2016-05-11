// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class BATTERYCOLLECTOR_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	/* Returns the WhereToSpawn subobject, the const after the function is saying the function is constant and not the variable allowing a slight speed increase */
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	/* Find a random point within the BoxComponent */
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();

	/* This function toggles wether or not the spawn volume spawns pickups */
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SetSpawningActive(bool bShouldSpawn);

protected:
	/* The pickup to spawn */
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;

	FTimerHandle SpawnTimer;

	/* Minimum spawn delay*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow;

	/* Max spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning" )
	float SpawnDelayRangeHigh;

private:
	/* Box component to specify where pickups should be spawned */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;
	
	/* Handle spawning a new pickup */
	void SpawnPickup();
	
	/* the current spawn delay */
	float SpawnDelay;

};
