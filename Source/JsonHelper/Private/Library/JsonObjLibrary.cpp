// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/JsonObjLibrary.h"
#include "Json.h"
#include "Object/JsonObj.h"

UJsonObj* UJsonObjLibrary::ConstructJsonObject()
{
	TSharedPtr<FJsonObject> JsonObj = MakeShareable(new FJsonObject());
	UJsonObj* Obj = NewObject<UJsonObj>();
	if (Obj)
	{
		Obj->SetJsonObj(JsonObj);
		return Obj;
	}
	return nullptr;
}

UJsonObj* UJsonObjLibrary::ConstructJsonObjectFromJsonString(const FString& JsonString)
{
	TSharedPtr<FJsonObject> JsonObj = MakeShareable(new FJsonObject());
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonString);
	if (FJsonSerializer::Deserialize(JsonReader, JsonObj))
	{
		UJsonObj* Obj = UJsonObjLibrary::ConstructJsonObjectWithJsonObject(JsonObj);
		return Obj;
	}
	return nullptr;
}

UJsonObj* UJsonObjLibrary::ConstructJsonObjectWithJsonObject(TSharedPtr<FJsonObject> InObj)
{
	UJsonObj* Obj = NewObject<UJsonObj>();
	if (Obj)
	{
		Obj->SetJsonObj(InObj);
	}
	return Obj;
}

bool UJsonObjLibrary::ConstructJsonObjectArrayFromJsonString(const FString& JsonString, TArray<UJsonObj*>& OutObjArray)
{
	TArray<UJsonObj*> OutObjs;
	TArray<TSharedPtr<FJsonValue>> OutArray;
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonString);
	bool bFlag = FJsonSerializer::Deserialize(JsonReader, OutArray);
	if (!bFlag)
	{
		UE_LOG(LogTemp, Error, TEXT("UJsonHelperLibrary::DeserializeJsonArray---Deserialize Failed!"));
		return false;
	}
	for (const TSharedPtr<FJsonValue>& elem : OutArray)
	{
		UJsonObj* Obj = UJsonObjLibrary::ConstructJsonObjectWithJsonObject(elem->AsObject());
		OutObjs.Add(Obj);
	}
	OutObjArray = OutObjs;
	return true;
}

