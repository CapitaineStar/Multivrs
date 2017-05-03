// Fill out your copyright notice in the Description page of Project Settings.

#include "Multivrs.h"
#include "WindDataFactory.h"

UWindDataFactory::UWindDataFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = false;
	bEditorImport = true;
	SupportedClass = UWindData::StaticClass();
	Formats.Add(TEXT("wind;Custom Wind Data"));
}

// Importer
UObject * UWindDataFactory::FactoryCreateFile(
	UClass * InClass, 
	UObject * InParent, 
	FName InName, 
	EObjectFlags Flags, 
	const FString & Filename, 
	const TCHAR * Parms, 
	FFeedbackContext * Warn, 
	bool & bOutOperationCanceled)
{
	UWindData* WindDataAsset = NewObject<UWindData>(InParent, InClass, InName, Flags);
	LoadWindData(Filename, *WindDataAsset);
	
	return WindDataAsset;
}

bool UWindDataFactory::LoadWindData(FString FilePath, UWindData& WindDataObject)
{
	// Load Wind Data file to string array
	TArray<FString> SplineArray;
	if (!FFileHelper::LoadANSITextFileToStrings(*FilePath, NULL, SplineArray))
	{
		UE_LOG(LogTemp, Warning, TEXT("Wind Data Import: Unable to load file."));
		return false;
	}

	// For each array item (spline)
	for (const FString& EachSpline : SplineArray)
	{
		if (EachSpline == "")
			continue;
		
		// Construct a Speck (array of spline points)
		FWindSpeck Speck;

		// For each point in spline
		TArray<FString> PointPos;
		EachSpline.ParseIntoArray(PointPos, TEXT(";"), true);
		for (const FString& Pt : PointPos)
		{
			TArray<FString> Coord;
			Pt.ParseIntoArray(Coord, TEXT(","), true);
			float x, y, z;
			x = FCString::Atof(*Coord[0]);
			y = FCString::Atof(*Coord[1]);
			z = FCString::Atof(*Coord[2]);

			// Add point to spline
			Speck.CurvePointPositions.Add(FVector(x,y,z));
		}

		// Add Speck to Object array
		WindDataObject.AddWindSpeck(Speck);
	}

	UE_LOG(LogTemp, Log, TEXT("Wind Data Import: Number of Specks = %d"), WindDataObject.GetWindSpeckNum());
	return true;
}
