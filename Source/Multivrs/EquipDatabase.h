// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataAsset.h"
#include "EquipDatabase.generated.h"

struct FSlateBrush;

USTRUCT(BlueprintType)
struct FEquipInfo {

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	TSubclassOf<AActor> equipClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	float chanceWeight = 1.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FText equipName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FText equipFluffText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FText equipAbilityName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FText equipAbilityDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FString equipAbilityHexPattern = "+";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	float equipAbilityCost = 1.0;
};

/**
 * 
 */
UCLASS(BlueprintType)
class MULTIVRS_API UEquipDatabase : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	TArray<FEquipInfo> equipsList;
	
};
