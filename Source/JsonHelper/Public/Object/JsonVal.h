// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "JsonVal.generated.h"

UENUM(BlueprintType)
enum class EJsonValType : uint8
{
	None,
	Null,
	String,
	Number,
	Boolean,
	Array,
	Object
};
class FJsonValue;
class UJsonObj;
/**
 * 
 */
USTRUCT(BlueprintType)
struct JSONHELPER_API FJsonVal
{
	GENERATED_BODY()

public:

	FJsonVal(){};
	FJsonVal(TSharedPtr<FJsonValue> InVal) : Value(InVal){};

	TSharedPtr<FJsonValue> GetValue() const;
	EJsonValType		   GetType()  const;

	bool AsString (FString& Out)          const;
	bool AsNumber (float& Out)            const;
	bool AsBoolean(bool& Out)             const;
	bool AsArray  (TArray<FJsonVal>& Out) const;
	bool AsObject (UJsonObj*& Out)        const;

private:

	TSharedPtr<FJsonValue> Value;
};
