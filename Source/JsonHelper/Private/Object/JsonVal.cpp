// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/JsonVal.h"
#include "Object/JsonObj.h"
#include "Library/JsonObjLibrary.h"

TSharedPtr<FJsonValue> FJsonVal::GetValue() const
{
	return Value;
}

EJsonValType FJsonVal::GetType() const
{
	return (EJsonValType)Value->Type;
}

bool FJsonVal::AsString(FString& Out) const
{
	bool bRet = Value.IsValid();
	if (bRet)
	{
		Out = Value->AsString();
	}
	return bRet;
}

bool FJsonVal::AsNumber(float& Out) const
{
	bool bRet = Value.IsValid();
	if (bRet)
	{
		Out = Value->AsNumber();
	}
	return bRet;
}

bool FJsonVal::AsBoolean(bool& Out) const
{
	bool bRet = Value.IsValid();
	if (bRet)
	{
		Out = Value->AsBool();
	}
	return bRet;
}

bool FJsonVal::AsArray(TArray<FJsonVal>& Out) const
{
	bool bRet = Value.IsValid();
	if (bRet)
	{
		for (const TSharedPtr<FJsonValue>& Elem : Value->AsArray())
		{
			Out.Add(FJsonVal(Elem));
		}
	}
	return bRet;
}


bool FJsonVal::AsObject(UJsonObj*& Out) const
{
	bool bRet = Value.IsValid();
	if (bRet)
	{
		UJsonObj* Obj = UJsonObjLibrary::ConstructJsonObjectWithJsonObject(Value->AsObject());
	}
	return bRet;
}