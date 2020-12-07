// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/JsonVal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JsonValLibrary.generated.h"
class UJsonObj;
/**
 * 
 */
UCLASS()
class JSONHELPER_API UJsonValLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Factory")
		static FJsonVal               ConstructJsonValString(const FString& InVal);
		static TSharedPtr<FJsonValue> ConstructJsonValueString(const FString& InVal);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Factory")
		static FJsonVal               ConstructJsonValNumber(float InVal);
		static TSharedPtr<FJsonValue> ConstructJsonValueNumber(float InVal);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Factory")
		static FJsonVal               ConstructJsonValBoolean(bool InVal);
		static TSharedPtr<FJsonValue> ConstructJsonValueBoolean(bool InVal);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Factory")
		static FJsonVal               ConstructJsonValObject(const UJsonObj* InVal);
		static TSharedPtr<FJsonValue> ConstructJsonValueObject(const UJsonObj* InVal);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Factory")
		static FJsonVal               ConstructJsonValArray(const TArray<FJsonVal>& InVal);
		static FJsonVal               ConstructJsonValArray(const TArray<TSharedPtr<FJsonValue>>& InVal);
		static TSharedPtr<FJsonValue> ConstructJsonValueArray(const TArray<FJsonVal>& InVal);
		static TSharedPtr<FJsonValue> ConstructJsonValueArray(const TArray<TSharedPtr<FJsonValue>>& InVal);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Factory")
		static FJsonVal               ConstructJsonValStringArray(const TArray<FString>& InVal);
		static TSharedPtr<FJsonValue> ConstructJsonValueStringArray(const TArray<FString>& InVal);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Factory")
		static FJsonVal               ConstructJsonValNumberArray(const TArray<float>& InVal);
		static TSharedPtr<FJsonValue> ConstructJsonValueNumberArray(const TArray<float>& InVal);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Factory")
		static FJsonVal               ConstructJsonValBooleanArray(const TArray<bool>& InVal);
		static TSharedPtr<FJsonValue> ConstructJsonValueBooleanArray(const TArray<bool>& InVal);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Factory")
		static FJsonVal               ConstructJsonValObjectArray(const TArray<UJsonObj*>& InVal);
		static TSharedPtr<FJsonValue> ConstructJsonValueObjectArray(const TArray<UJsonObj*>& InVal);


	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Getter")
		static bool GetValueAsString(const FJsonVal& Val, FString& Out);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Getter")
		static bool GetValueAsNumber(const FJsonVal& Val, float& Out);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Getter")
		static bool GetValueAsBoolean(const FJsonVal& Val, bool& Out);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Getter")
		static bool GetValueAsArray(const FJsonVal& Val, TArray<FJsonVal>& Out);
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ValLib|Getter")
		static bool GetValueAsObject(const FJsonVal& Val, UJsonObj*& Out);
};
