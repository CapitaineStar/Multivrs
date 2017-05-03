// Fill out your copyright notice in the Description page of Project Settings.

#include "Multivrs.h"
#include "WindData.h"

UWindData::UWindData(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

int32 UWindData::GetWindSpeckNum()
{
	return WindSpeckArray.Num();
}

TArray<FVector> UWindData::GetWindSpeck(int32 WindIndex)
{
	return WindSpeckArray[WindIndex].CurvePointPositions;
}

void UWindData::AddWindSpeck(FWindSpeck NewSpeck)
{
	WindSpeckArray.Add(NewSpeck);
}
