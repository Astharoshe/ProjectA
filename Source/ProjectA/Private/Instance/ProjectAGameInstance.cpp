// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectAGameInstance.h"
#include "Engine/DataTable.h"
#include "CharacterData.h"
//#include "Engine/StreamableManager.h"

UProjectAGameInstance::UProjectAGameInstance()
{

}

void UProjectAGameInstance::Init()
{
	Super::Init();

}

FCharacterData* UProjectAGameInstance::GetCharacterData(int32 _Level)
{
	CHECKASSERT(nullptr != m_CharacterDataTable, nullptr);
	return m_CharacterDataTable->FindRow<FCharacterData>(*FString::FromInt(_Level), TEXT(""));
}

FStreamableManager* UProjectAGameInstance::GetStreamableMgr()
{
	return &m_StreamableMgr;
}

void UProjectAGameInstance::LoadDataTable()
{
	FString DataPath = TEXT("123");
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTable(*DataPath);
	if (DataTable.Succeeded())
	{
		m_CharacterDataTable = DataTable.Object;
	}
}
