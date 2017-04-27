// Fill out your copyright notice in the Description page of Project Settings.

#include "Multivrs.h"
#include "EnvQueryTest_Axis.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

UEnvQueryTest_Axis::UEnvQueryTest_Axis(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	Cost = EEnvTestCost::Low;
	ValidItemType = UEnvQueryItemType_VectorBase::StaticClass();
}

void UEnvQueryTest_Axis::RunTest(FEnvQueryInstance & QueryInstance) const
{
	UObject* QueryOwner = QueryInstance.Owner.Get();
	if (QueryOwner == nullptr)
	{
		return;
	}
	
	FloatValueMin.BindData(QueryOwner, QueryInstance.QueryID);
	float MinThresholdValue = FloatValueMin.GetValue();

	FloatValueMax.BindData(QueryOwner, QueryInstance.QueryID);
	float MaxThresholdValue = FloatValueMax.GetValue();

	switch (AxisTest)
	{
		case EEnvTestAxis::X:
			for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It)
			{
				const FVector ItemLocation = GetItemLocation(QueryInstance, It.GetIndex());
				It.SetScore(TestPurpose, FilterType, ItemLocation.X, MinThresholdValue, MaxThresholdValue);
			}
			break;

		case EEnvTestAxis::Y:
			for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It)
			{
				const FVector ItemLocation = GetItemLocation(QueryInstance, It.GetIndex());
				It.SetScore(TestPurpose, FilterType, ItemLocation.Y, MinThresholdValue, MaxThresholdValue);
			}
			break;

		case EEnvTestAxis::Z:
			for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It)
			{
				const FVector ItemLocation = GetItemLocation(QueryInstance, It.GetIndex());
				It.SetScore(TestPurpose, FilterType, ItemLocation.Z, MinThresholdValue, MaxThresholdValue);
			}
			break;

		default:
			checkNoEntry();
			return;
	}
}

FText UEnvQueryTest_Axis::GetDescriptionTitle() const
{
	FString ModeDesc;
	switch (AxisTest)
	{
	case EEnvTestAxis::X:
		ModeDesc = TEXT("Axis X");
		break;

	case EEnvTestAxis::Y:
		ModeDesc = TEXT("Axis Y");
		break;

	case EEnvTestAxis::Z:
		ModeDesc = TEXT("Axis Z");
		break;

	default:
		break;
	}

	return FText::FromString(FString::Printf(TEXT("%s"), *ModeDesc));
}

FText UEnvQueryTest_Axis::GetDescriptionDetails() const
{
	return FText::FromString(FString::Printf(TEXT("Axis Test")));
}