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
	float chanceWeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FText equipName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FText equipDescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	UTexture2D* equipTexture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FText equipAbilityName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	FText equipAbilityDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Multivrs")
	float equipAbilityTime;
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
