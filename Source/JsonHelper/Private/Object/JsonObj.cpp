// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/JsonObj.h"
#include "Json.h"
#include "Dom/JsonValue.h"
#include "JsonHelperPCH.h"
#include "Library/JsonValLibrary.h"
#include "Library/JsonObjLibrary.h"


bool UJsonObj::IsValid() const
{
	return this->Obj || this->Obj.IsValid();
}

FString UJsonObj::ToJsonStr() const
{
	FString JsonStr;
	if (this->Obj.IsValid() && this->Obj->Values.Num() > 0)
	{
		TSharedRef<TJsonWriter<TCHAR>> t_writer = TJsonWriterFactory<>::Create(&JsonStr);
		FJsonSerializer::Serialize(this->Obj.ToSharedRef(), t_writer);
	}
	return JsonStr;
}

TSharedPtr<FJsonObject> UJsonObj::GetJsonObj() const
{
	return this->Obj;
}

void UJsonObj::SetJsonObj(TSharedPtr<FJsonObject> NewObj)
{
	this->Obj = NewObj;
}

bool UJsonObj::GetField(const FString& Field, FJsonVal& Out)
{
	bool bRet = false;
	if (!IsValid())
	{
		UE_LOG(LogJsonHelper, Error, TEXT("UJsonObj------Object is NOT VALID!"));
		return bRet;
	}
	TSharedPtr<FJsonValue> Temp;
	bRet = GetField(Field, Temp);
	Out = FJsonVal(Temp);
	return bRet;
}

bool UJsonObj::GetField(const FString& Field, TSharedPtr<FJsonValue>& Out)
{
	bool bRet = false;
	if (!IsValid())
	{
		UE_LOG(LogJsonHelper, Error, TEXT("UJsonObj------Object is NOT VALID!"));
		return bRet;
	}
	Out = this->Obj->TryGetField(Field);
	bRet = Out.IsValid();
	return bRet;
}

bool UJsonObj::SetField(const FString& Field, const FJsonVal& InVal)
{
	return this->SetField(Field, InVal.GetValue());
}

bool UJsonObj::SetField(const FString& Field, const TSharedPtr<FJsonValue> InVal)
{
	if (!IsValid())
	{
		UE_LOG(LogJsonHelper, Error, TEXT("UJsonObj------Object is NOT VALID!"));
		return false;
	}
	this->Obj->SetField(Field, InVal);
	return true;
}

bool UJsonObj::GetStringField(const FString& Field, FString& Out)
{
	TSharedPtr<FJsonValue> Temp; 
	if (!this->GetField(Field, Temp) || !Temp.IsValid())
	{
		return false;
	}
	Out = Temp->AsString();
	return true;
}

bool UJsonObj::SetStringField(const FString& Field, const FString& InVal)
{
	return this->SetField(Field, UJsonValLibrary::ConstructJsonValueString(InVal));
}

bool UJsonObj::GetNumberField(const FString& Field, float& Out)
{
	TSharedPtr<FJsonValue> Temp;
	if (!this->GetField(Field, Temp) || !Temp.IsValid())
	{
		return false;
	}
	Out = Temp->AsNumber();
	return true;
}

bool UJsonObj::SetNumberField(const FString& Field, const float& InVal)
{
	return this->SetField(Field, UJsonValLibrary::ConstructJsonValueNumber(InVal));
}

bool UJsonObj::GetBooleanField(const FString& Field, bool& Out)
{
	TSharedPtr<FJsonValue> Temp;
	if (!this->GetField(Field, Temp) || !Temp.IsValid())
	{
		return false;
	}
	Out = Temp->AsBool();
	return true;
}

bool UJsonObj::SetBooleanField(const FString& Field, const bool& InVal)
{
	return this->SetField(Field, UJsonValLibrary::ConstructJsonValueBoolean(InVal));
}


bool UJsonObj::GetObjectField(const FString& Field, UJsonObj*& Out)
{
	TSharedPtr<FJsonValue> Temp;
	if (!this->GetField(Field, Temp) || !Temp.IsValid())
	{
		return false;
	}
	Out = UJsonObjLibrary::ConstructJsonObjectWithJsonObject(Temp->AsObject());
	return true;
}

bool UJsonObj::SetObjectField(const FString& Field, const UJsonObj* InVal)
{
	return this->SetField(Field, UJsonValLibrary::ConstructJsonValueObject(InVal));
}

bool UJsonObj::GetArrayField(const FString& Field, TArray<FJsonVal>& Out)
{
	TSharedPtr<FJsonValue> Temp;
	if (!this->GetField(Field, Temp) || !Temp.IsValid())
	{
		return false;
	}
	for (const TSharedPtr<FJsonValue>& elem : Temp->AsArray())
	{
		Out.Add(FJsonVal(elem));
	}

	return true;
}

bool UJsonObj::GetArrayField(const FString& Field, TArray<TSharedPtr<FJsonValue>>& Out)
{
	TSharedPtr<FJsonValue> Temp;
	if (!this->GetField(Field, Temp) || !Temp.IsValid())
	{
		return false;
	}
	for (const TSharedPtr<FJsonValue>& elem : Temp->AsArray())
	{
		Out.Add(elem);
	}
	return true;
}

bool UJsonObj::SetArrayField(const FString& Field, const TArray<FJsonVal>& InVal)
{
	return this->SetField(Field, UJsonValLibrary::ConstructJsonValueArray(InVal));
}

bool UJsonObj::SetArrayField(const FString& Field, const TArray<TSharedPtr<FJsonValue>>& InVal)
{
	return this->SetField(Field, UJsonValLibrary::ConstructJsonValueArray(InVal));
}

bool UJsonObj::GetStringArrayField(const FString& Field, TArray<FString>& Out)
{
	TSharedPtr<FJsonValue> Temp;
	if (!this->GetField(Field, Temp) || !Temp.IsValid())
	{
		return false;
	}
	for (const TSharedPtr<FJsonValue>& elem : Temp->AsArray())
	{
		Out.Add(elem->AsString());
	}
	return true;
}

bool UJsonObj::SetStringArrayField(const FString& Field, const TArray<FString>& InVal)
{
	return this->SetField(Field, UJsonValLibrary::ConstructJsonValueStringArray(InVal));
}

bool UJsonObj::GetNumberArrayField(const FString& Field, TArray<float>& Out)
{
	TSharedPtr<FJsonValue> Temp;
	if (!this->GetField(Field, Temp) || !Temp.IsValid())
	{
		return false;
	}
	for (const TSharedPtr<FJsonValue>& elem : Temp->AsArray())
	{
		Out.Add(elem->AsNumber());
	}
	return true;
}

bool UJsonObj::SetNumberArrayField(const FString& Field, const TArray<float>& InVal)
{
	return this->SetField(Field, UJsonValLibrary::ConstructJsonValueNumberArray(InVal));
}

bool UJsonObj::GetBooleanArrayField(const FString& Field, TArray<bool>& Out)
{
	TSharedPtr<FJsonValue> Temp;
	if (!this->GetField(Field, Temp) || !Temp.IsValid())
	{
		return false;
	}
	for (const TSharedPtr<FJsonValue>& elem : Temp->AsArray())
	{
		Out.Add(elem->AsBool());
	}
	return true;
}

bool UJsonObj::SetBooleanArrayField(const FString& Field, const TArray<bool>& InVal)
{
	return this->SetField(Field, UJsonValLibrary::ConstructJsonValueBooleanArray(InVal));
}

bool UJsonObj::GetObjectArrayField(const FString& Field, TArray<UJsonObj*>& Out)
{
	TSharedPtr<FJsonValue> Temp;
	if (!this->GetField(Field, Temp) || !Temp.IsValid())
	{
		return false;
	}
	for (const TSharedPtr<FJsonValue>& elem : Temp->AsArray())
	{
		Out.Add(UJsonObjLibrary::ConstructJsonObjectWithJsonObject(elem->AsObject()));
	}
	return true;
}

bool UJsonObj::SetObjectArrayField(const FString& Field, const TArray<UJsonObj*>& InVal)
{
	return this->SetField(Field, UJsonValLibrary::ConstructJsonValueObjectArray(InVal));
}
