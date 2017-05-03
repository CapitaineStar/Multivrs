// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Factories/Factory.h"
#include "WindData.h"
#include "WindDataFactory.generated.h"

/**
 * 
 */
UCLASS()
class MULTIVRS_API UWindDataFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Parms, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
	
	static bool LoadWindData(FString FilePath, UWindData& WindDataObject);
};
