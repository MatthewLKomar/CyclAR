// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CommonTextBlock.h"
#include "Dashboard.generated.h"

class UDataDistributor;

/**
 * Dashboard widget displaying time and odometry (speed, trip duration).
 */
UCLASS()
class CYCLAR_API UDashboard : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

public:
	/** Echoes system time and sets Time_Hour, Time_Minute, Time_Merdian text blocks. */
	UFUNCTION(BlueprintCallable, Category = "Dashboard")
	void UpdateSystemTimeDisplay();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> Time_Hour;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> Time_Minute;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> Time_Merdian;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> Odometry_Speed;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> Odometry_TripDuration;

private:
	void OnTripDurationUpdated(float TripDuration);
	void OnCurrentSpeedUpdated(float CurrentSpeed);
};
