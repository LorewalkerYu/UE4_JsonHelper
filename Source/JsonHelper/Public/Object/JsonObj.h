// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "JsonVal.h"
#include "JsonObj.generated.h"

/**
 * 
 */
UCLASS()
class JSONHELPER_API UJsonObj : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|JsonObj|Getter")
		bool IsValid() const;
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|JsonObj|Getter")
		FString ToJsonStr() const;

	TSharedPtr<FJsonObject> GetJsonObj()const;
	void                    SetJsonObj(TSharedPtr<FJsonObject> NewObj);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "JsonHelper|JsonObj|Getter")
		bool GetField(const FString& Field, FJsonVal& Out);
		bool GetField(const FString& Field, TSharedPtr<FJsonValue>& Out);
	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Setter")
		bool SetField(const FString& Field, const FJsonVal& InVal);
		bool SetField(const FString& Field, const TSharedPtr<FJsonValue> InVal);

	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Getter")
		bool GetStringField(const FString& Field, FString& Out);
	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Setter")
		bool SetStringField(const FString& Field, const FString& InVal);

	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Getter")
		bool GetNumberField(const FString& Field, float& Out);
	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Setter")
		bool SetNumberField(const FString& Field, const float& InVal);

	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Getter")
		bool GetBooleanField(const FString& Field, bool& Out);
	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Setter")
		bool SetBooleanField(const FString& Field, const bool& InVal);

	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Getter")
		bool GetObjectField(const FString& Field, UJsonObj*& Out);
	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Setter")
		bool SetObjectField(const FString& Field, const UJsonObj* InVal);

	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Getter")
		bool GetArrayField(const FString& Field, TArray<FJsonVal>& Out);
		bool GetArrayField(const FString& Field, TArray<TSharedPtr<FJsonValue>>& Out);
	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Setter")
		bool SetArrayField(const FString& Field, const TArray<FJsonVal>& InVal);
		bool SetArrayField(const FString& Field, const TArray<TSharedPtr<FJsonValue>>& InVal);

	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Getter")
		bool GetStringArrayField(const FString& Field, TArray<FString>& Out);
	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Setter")
		bool SetStringArrayField(const FString& Field, const TArray<FString>& InVal);

	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Getter")
		bool GetNumberArrayField(const FString& Field, TArray<float>& Out);
	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Setter")
		bool SetNumberArrayField(const FString& Field, const TArray<float>& InVal);

	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Getter")
		bool GetBooleanArrayField(const FString& Field, TArray<bool>& Out);
	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Setter")
		bool SetBooleanArrayField(const FString& Field, const TArray<bool>& InVal);

	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Getter")
		bool GetObjectArrayField(const FString& Field, TArray<UJsonObj*>& Out);
	UFUNCTION(BlueprintCallable, Category = "JsonHelper|JsonObj|Setter")
		bool SetObjectArrayField(const FString& Field, const TArray<UJsonObj*>& InVal);

private:

	TSharedPtr<FJsonObject> Obj;
};
