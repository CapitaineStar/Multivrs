// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "HexDatabase.generated.h"

/**
 * 
 */
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EHexType : uint8
{
	HT_Default 		UMETA(DisplayName = "Default"),
	HT_Shelter 		UMETA(DisplayName = "Shelter"),
	HT_Portal 		UMETA(DisplayName = "Portal"),
	HT_Equipment 	UMETA(DisplayName = "Equipment"),
	HT_Blocker		UMETA(DisplayName = "Blocker")
};

USTRUCT(BlueprintType)
struct FHexInfo {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Multivrs")
	EHexType hexType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	TSubclassOf<AActor> hexClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	float chanceWeight;
};

UCLASS(BlueprintType)
class MULTIVRS_API UHexDatabase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Multivrs")
	TArray<FHexInfo> hexItems;

	/*
	*Finds the index of the first instance of the type within the database
	*@param		TypeToFind		The type to look for
	*@return	The index the type was found at, or -1 if not found
	*/
	UFUNCTION(BlueprintPure, Category = "Multivrs")
	int32 FindHexType(const EHexType& TypeToFind);
	
	/*
	*Finds the index of a random instance of the type within the database
	*/
	UFUNCTION(BlueprintPure, Category = "Multivrs")
	int32 FindHexTypeRandom(const EHexType& TypeToFind, const FRandomStream& Stream);
};
