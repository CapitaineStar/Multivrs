// Fill out your copyright notice in the Description page of Project Settings.

#include "Multivrs.h"
#include "HexDatabase.h"

int32 UHexDatabase::FindHexType(const EHexType & TypeToFind)
{
	int32 ResultIndex = INDEX_NONE;

	if (UHexDatabase::hexList.Num() != 0)
	{
		// compare against each element in the array
		for (int32 Idx = 0; Idx < hexList.Num() && ResultIndex == INDEX_NONE; Idx++)
		{
			if (UHexDatabase::hexList[Idx].hexType == TypeToFind)
			{
				// assign the resulting index
				ResultIndex = Idx;
			}
		}
	}

	return ResultIndex;
}

int32 UHexDatabase::FindHexTypeRandom(const EHexType & TypeToFind, const FRandomStream & Stream)
{
	TArray<int32> ResultsFind;

	if (UHexDatabase::hexList.Num() != 0)
	{
		// compare against each element in the array and add to result array
		for (int32 Idx = 0; Idx < hexList.Num(); Idx++)
		{
			if (UHexDatabase::hexList[Idx].hexType == TypeToFind)
			{
				ResultsFind.Emplace(Idx);
			}
		}
	}

	//return a random index if there's a result
	if (ResultsFind.Num() != 0)
		return ResultsFind[Stream.RandRange( 0, ResultsFind.Num()-1 )];
	else
		return INDEX_NONE;
}
