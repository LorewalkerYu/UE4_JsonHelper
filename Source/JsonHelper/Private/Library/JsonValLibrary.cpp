// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/JsonValLibrary.h"
#include "Json.h"
#include "Object/JsonObj.h"

FJsonVal UJsonValLibrary::ConstructJsonValString(const FString& InVal)
{
	return FJsonVal(ConstructJsonValueString(InVal));
}

TSharedPtr<FJsonValue> UJsonValLibrary::ConstructJsonValueString(const FString& InVal)
{
	return MakeShared<FJsonValueString>(InVal);
}

FJsonVal UJsonValLibrary::ConstructJsonValNumber(float InVal)
{
	return FJsonVal(ConstructJsonValueNumber(InVal));
}

TSharedPtr<FJsonValue> UJsonValLibrary::ConstructJsonValueNumber(float InVal)
{
	return MakeShared<FJsonValueNumber>(InVal);
}

FJsonVal UJsonValLibrary::ConstructJsonValBoolean(bool InVal)
{
	return FJsonVal(ConstructJsonValueBoolean(InVal));
}

TSharedPtr<FJsonValue> UJsonValLibrary::ConstructJsonValueBoolean(bool InVal)
{
	return MakeShared<FJsonValueBoolean>(InVal);
}

FJsonVal UJsonValLibrary::ConstructJsonValObject(const UJsonObj* InVal)
{
	return FJsonVal(ConstructJsonValueObject(InVal));
}

TSharedPtr<FJsonValue> UJsonValLibrary::ConstructJsonValueObject(const UJsonObj* InVal)
{
	return MakeShared<FJsonValueObject>(InVal->GetJsonObj());
}

FJsonVal UJsonValLibrary::ConstructJsonValArray(const TArray<FJsonVal>& InVal)
{
	return FJsonVal(ConstructJsonValueArray(InVal));
}

FJsonVal UJsonValLibrary::ConstructJsonValArray(const TArray<TSharedPtr<FJsonValue>>& InVal)
{
	return MakeShared<FJsonValueArray>(InVal);
}

TSharedPtr<FJsonValue> UJsonValLibrary::ConstructJsonValueArray(const TArray<FJsonVal>& InVal)
{
	TArray<TSharedPtr<FJsonValue>> Array;
	for (const FJsonVal& elem : InVal)
	{
		Array.Add(elem.GetValue());
	}
	return ConstructJsonValueArray(Array);
}

TSharedPtr<FJsonValue> UJsonValLibrary::ConstructJsonValueArray(const TArray<TSharedPtr<FJsonValue>>& InVal)
{
	return MakeShared<FJsonValueArray>(InVal);
}

FJsonVal UJsonValLibrary::ConstructJsonValStringArray(const TArray<FString>& InVal)
{
	return FJsonVal(ConstructJsonValueStringArray(InVal));
}

TSharedPtr<FJsonValue> UJsonValLibrary::ConstructJsonValueStringArray(const TArray<FString>& InVal)
{
	TArray<TSharedPtr<FJsonValue>> Temp; ;
	for (const FString& elem : InVal)
	{
		Temp.Add(ConstructJsonValueString(elem));
	}
	return ConstructJsonValueArray(Temp);
}

FJsonVal UJsonValLibrary::ConstructJsonValNumberArray(const TArray<float>& InVal)
{
	return FJsonVal(ConstructJsonValueNumberArray(InVal));
}

TSharedPtr<FJsonValue> UJsonValLibrary::ConstructJsonValueNumberArray(const TArray<float>& InVal)
{
	TArray<TSharedPtr<FJsonValue>> Temp; ;
	for (const float& elem : InVal)
	{
		Temp.Add(ConstructJsonValueNumber(elem));
	}
	return ConstructJsonValueArray(Temp);
}

FJsonVal UJsonValLibrary::ConstructJsonValBooleanArray(const TArray<bool>& InVal)
{
	return FJsonVal(ConstructJsonValueBooleanArray(InVal));
}

TSharedPtr<FJsonValue> UJsonValLibrary::ConstructJsonValueBooleanArray(const TArray<bool>& InVal)
{
	TArray<TSharedPtr<FJsonValue>> Temp; 
	for (const bool& elem : InVal)
	{
		Temp.Add(ConstructJsonValueBoolean(elem));
	}
	return ConstructJsonValueArray(Temp);
}

FJsonVal UJsonValLibrary::ConstructJsonValObjectArray(const TArray<UJsonObj*>& InVal)
{
	return FJsonVal(ConstructJsonValueObjectArray(InVal));
}

TSharedPtr<FJsonValue> UJsonValLibrary::ConstructJsonValueObjectArray(const TArray<UJsonObj*>& InVal)
{
	TArray<TSharedPtr<FJsonValue>> Temp; 
	for (const UJsonObj* elem : InVal)
	{
		Temp.Add(ConstructJsonValueObject(elem));
	}
	return ConstructJsonValueArray(Temp);
}

bool UJsonValLibrary::GetValueAsString(const FJsonVal& Val, FString& Out) 
{
	return Val.AsString(Out);
}

bool UJsonValLibrary::GetValueAsNumber(const FJsonVal& Val, float& Out) 
{
	return Val.AsNumber(Out);
}

bool UJsonValLibrary::GetValueAsBoolean(const FJsonVal& Val, bool& Out) 
{
	return Val.AsBoolean(Out);
}

bool UJsonValLibrary::GetValueAsArray(const FJsonVal& Val, TArray<FJsonVal>& Out) 
{
	return Val.AsArray(Out);
}

bool UJsonValLibrary::GetValueAsObject(const FJsonVal& Val, UJsonObj*& Out) 
{
	return Val.AsObject(Out);

}
