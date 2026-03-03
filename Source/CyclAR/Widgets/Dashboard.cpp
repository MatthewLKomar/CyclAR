// Fill out your copyright notice in the Description page of Project Settings.

#include "Dashboard.h"
#include "Utility/DataDistributor.h"
#include "Engine/GameInstance.h"

void UDashboard::NativeConstruct()
{
	Super::NativeConstruct();

	UDataDistributor* DataDistributor = GetGameInstance() ? GetGameInstance()->GetSubsystem<UDataDistributor>() : nullptr;
	if (DataDistributor)
	{
		DataDistributor->Odometry_TripDuration.AddUObject(this, &UDashboard::OnTripDurationUpdated);
		DataDistributor->Odometry_CurrentSpeed.AddUObject(this, &UDashboard::OnCurrentSpeedUpdated);

		// Set initial values from cached data if available
		OnTripDurationUpdated(DataDistributor->GetCachedTripDuration());
		OnCurrentSpeedUpdated(DataDistributor->GetCachedCurrentSpeed());
	}

	UpdateSystemTimeDisplay();
}

void UDashboard::NativeDestruct()
{
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UDataDistributor* DataDistributor = GI->GetSubsystem<UDataDistributor>())
		{
			DataDistributor->Odometry_TripDuration.RemoveAll(this);
			DataDistributor->Odometry_CurrentSpeed.RemoveAll(this);
		}
	}
	Super::NativeDestruct();
}

void UDashboard::UpdateSystemTimeDisplay()
{
	FDateTime Now = FDateTime::Now();
	int32 Hour12 = Now.GetHour() % 12;
	if (Hour12 == 0) Hour12 = 12;
	int32 Minute = Now.GetMinute();

	FString Meridian = (Now.GetHour() < 12) ? TEXT("AM") : TEXT("PM");

	if (Time_Hour)
	{
		Time_Hour->SetText(FText::FromString(FString::FromInt(Hour12)));
	}
	if (Time_Minute)
	{
		Time_Minute->SetText(FText::FromString(FString::Printf(TEXT("%02d"), Minute)));
	}
	if (Time_Merdian)
	{
		Time_Merdian->SetText(FText::FromString(Meridian));
	}
}

void UDashboard::OnTripDurationUpdated(float TripDuration)
{
	if (Odometry_TripDuration)
	{
		int32 DurationInt = FMath::FloorToInt(TripDuration);
		Odometry_TripDuration->SetText(FText::AsNumber(DurationInt));
	}
}

void UDashboard::OnCurrentSpeedUpdated(float CurrentSpeed)
{
	if (Odometry_Speed)
	{
		int32 SpeedInt = FMath::FloorToInt(CurrentSpeed);
		Odometry_Speed->SetText(FText::AsNumber(SpeedInt));
	}
}
