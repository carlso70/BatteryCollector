// Fill out your copyright notice in the Description page of Project Settings.

#include "BatteryCollector.h"
#include "BatteryPickup.h"


//set default values
ABatteryPickup::ABatteryPickup()
{ 
	GetMesh()->SetSimulatePhysics(true);

	//The base power level of the battery
	BatteryPower = 150.f;
}


void ABatteryPickup::WasCollected_Implementation()
{
	// Use the base pickup behavior
	Super::WasCollected_Implementation();
	// Destroy the battery
	Destroy();
}

float ABatteryPickup::GetPower()
{
	return BatteryPower;
}