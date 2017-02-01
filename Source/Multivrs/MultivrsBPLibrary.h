// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MultivrsBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MULTIVRS_API UMultivrsBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintPure, Category = "MultivrsBPLibrary")
	static bool GetStaticMeshVertexLocations(UStaticMeshComponent* Comp, TArray<FVector>& VertexPositions);

	UFUNCTION(BlueprintPure, Category = "MultivrsBPLibrary")
	static bool GetStaticMeshVertex(UStaticMesh* SM, TArray<FVector>& VertexPositions, TArray<FColor>& VertexColors);
	
};
