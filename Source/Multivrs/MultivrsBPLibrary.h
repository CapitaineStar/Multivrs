// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SlateCore.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "MultivrsBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MULTIVRS_API UMultivrsBPLibrary : public UBlueprintFunctionLibrary
{
	
public:

	GENERATED_BODY()
	
	UFUNCTION(BlueprintPure, Category = "MultivrsBPLibrary")
	static bool GetStaticMeshVertexLocations(UStaticMeshComponent* Comp, TArray<FVector>& VertexPositions);

	UFUNCTION(BlueprintPure, Category = "MultivrsBPLibrary")
	static bool GetStaticMeshVertexInfo(UStaticMeshComponent* SM, TArray<FVector>& VertexPositions, TArray<FColor>& VertexColors);
	
	UFUNCTION(BlueprintCallable, Category = "MultivrsBPLibrary")
	static void DrawSpline(UPARAM(ref) FPaintContext& Context, FVector2D InStart, FVector2D InStartDir, FVector2D InEnd, FVector2D InEndDir,  FLinearColor Tint = FLinearColor::White, float Thickness = 1.0f);

};
