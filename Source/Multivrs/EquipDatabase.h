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
	FText fluffText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FText shelterAbilityName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FText shelterAbilityDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FString shelterSelectionPattern = "+";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	float shelterAbilityCost = 1.0;
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
