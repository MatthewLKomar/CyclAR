// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogCyclAR, Log, All);

#define SIMPLE_LOG(Level, FormatString, ...)											\
	UE_LOG(																				\
		LogCyclAR, Level, TEXT("[%s: line %d] - %s"), *FString(__FUNCTION__), __LINE__, \
		*FString::Printf(TEXT(FormatString), ##__VA_ARGS__));