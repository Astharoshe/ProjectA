// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectA.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"
#include "ProjectAGameInstance.generated.h"

class UDataTable;

struct FCharacterData;


/**
 * 
 */
UCLASS()
class PROJECTA_API UProjectAGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UProjectAGameInstance();

	virtual void Init() override;
	
	FCharacterData* GetCharacterData(int32 _Level);
	FStreamableManager* GetStreamableMgr();

protected:
	void LoadDataTable();

protected:
	UPROPERTY()
	UDataTable* m_CharacterDataTable;

	FStreamableManager m_StreamableMgr;
};
