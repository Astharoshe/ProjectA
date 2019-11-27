// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectA.h"
#include "Engine/GameInstance.h"
#include "ProjectAGameInstance.generated.h"

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
	
};
