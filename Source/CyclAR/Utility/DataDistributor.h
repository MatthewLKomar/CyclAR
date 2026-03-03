// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DataDistributor.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnTripDurationUpdated, float);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnCurrentSpeedUpdated, float);

/**
 * Subsystem that distributes odometry and other data via multicast delegates.
 */
UCLASS()
class CYCLAR_API UDataDistributor : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	/** Broadcast when trip duration is updated. */
	FOnTripDurationUpdated Odometry_TripDuration;

	/** Broadcast when current speed is updated. */
	FOnCurrentSpeedUpdated Odometry_CurrentSpeed;

	UFUNCTION(BlueprintCallable, Category = "Data Distributor")
	void UpdateTripDuration(float TripDuration);

	UFUNCTION(BlueprintCallable, Category = "Data Distributor")
	void UpdateCurrentSpeed(float CurrentSpeed);

	float GetCachedTripDuration() const { return CachedTripDuration; }
	float GetCachedCurrentSpeed() const { return CachedCurrentSpeed; }

private:
	float CachedTripDuration = 0.f;
	float CachedCurrentSpeed = 0.f;
};
