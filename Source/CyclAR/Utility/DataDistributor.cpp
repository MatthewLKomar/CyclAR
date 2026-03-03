// Fill out your copyright notice in the Description page of Project Settings.

#include "DataDistributor.h"

void UDataDistributor::UpdateTripDuration(float TripDuration)
{
	CachedTripDuration = TripDuration;
	Odometry_TripDuration.Broadcast(TripDuration);
}

void UDataDistributor::UpdateCurrentSpeed(float CurrentSpeed)
{
	CachedCurrentSpeed = CurrentSpeed;
	Odometry_CurrentSpeed.Broadcast(CurrentSpeed);
}
