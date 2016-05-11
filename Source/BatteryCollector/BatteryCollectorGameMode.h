// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "InputCoreTypes.h"
#include "BatteryCollectorGameMode.generated.h"

//enum to store the current state of gameplay
UENUM(BlueprintType)
enum class EBatteryPlayState
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryCollectorGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ABatteryCollectorGameMode();

	virtual void Tick(float DeltaTime) override;

	/* Returns Power needed to win - needed for the HUD */
	UFUNCTION(BlueprintPure, Category = "Power")
	float GetPowerToWin() const;

	/* Returns the current playing state */
	UFUNCTION(BlueprintPure, Category = "Power")
	EBatteryPlayState GetCurrentState() const;

	/* Sets a new playing state */
	void SetCurrentState(EBatteryPlayState NewState);

	virtual void BeginPlay() override;

protected: 
	/* Rate at which the character loses power */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	float DecayRate;

	/* Power needed to win the game */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	float PowerToWin;

	/* the widget class to use for our hud screen*/
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> HUDWidgetClass;

	/* The instance of the HUD */
	UPROPERTY()
	class UUserWidget* CurrentWidget;

private:
	/* Keep track of the current playing state */
	EBatteryPlayState CurrentState;

	TArray<class ASpawnVolume*> SpawnVolumeActors;

	/* Handle any function calls that rely upon changing the playing state of our game */
	void HandleCurrentState(EBatteryPlayState NewState);
};



