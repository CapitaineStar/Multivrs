// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "WindData.generated.h"

USTRUCT()
struct FWindSpeck
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TArray<FVector> CurvePointPositions;
};

/**
 * 
 */
UCLASS(Blueprintable)
class MULTIVRS_API UWindData : public UObject
{
	GENERATED_UCLASS_BODY()

public:

	UFUNCTION(BlueprintPure, Category = "Multivrs|Wind")
	int32 GetWindSpeckNum();

	UFUNCTION(BlueprintPure, Category = "Multivrs|Wind")
	TArray<FVector> GetWindSpeck(int32 WindIndex);

	UFUNCTION()
	void AddWindSpeck(FWindSpeck NewSpeck);

private:

	UPROPERTY()
	TArray<FWindSpeck> WindSpeckArray;
};
