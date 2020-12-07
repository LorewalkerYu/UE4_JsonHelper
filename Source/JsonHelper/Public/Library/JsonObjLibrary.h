// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JsonObjLibrary.generated.h"

/**
 * 
 */
UCLASS()
class JSONHELPER_API UJsonObjLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	/**
	 * Construct an empty json object
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ObjLib|Factory")
		static UJsonObj* ConstructJsonObject();

	/**
	 * Construct an json object from given json string
	 *
	 * @param   JsonString  The given json string
	 * @return              The constructed json object
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ObjLib|Factory")
		static UJsonObj* ConstructJsonObjectFromJsonString(const FString& JsonString);
		static UJsonObj* ConstructJsonObjectWithJsonObject(TSharedPtr<FJsonObject> InObj);
	/**
	 * Construct an json object from given json string
	 *
	 * @param   JsonString   The given json string
	 * @param   OutObjArray  The constructed json object array
	 * @return               Success
	 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|ObjLib|Factory")
		static bool ConstructJsonObjectArrayFromJsonString(const FString& JsonString, TArray<UJsonObj*>& OutObjArray);
};
