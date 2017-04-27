// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "Templates/SubclassOf.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "EnvQueryTest_Axis.generated.h"

UENUM()
namespace EEnvTestAxis
{
	enum Type
	{
		X,
		Y,
		Z
	};
}


UCLASS()
class MULTIVRS_API UEnvQueryTest_Axis : public UEnvQueryTest
{
	GENERATED_UCLASS_BODY()
	
	UPROPERTY(EditDefaultsOnly, Category = "Axis")
	TEnumAsByte<EEnvTestAxis::Type> AxisTest;

	virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;

	virtual FText GetDescriptionTitle() const override;
	virtual FText GetDescriptionDetails() const override;
};
