// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseData.h"
#include "CharacterData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct PROJECTA_API FCharacterData : public FBaseData
{
	GENERATED_USTRUCT_BODY()

public:
	FCharacterData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterData")
	FString Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterData")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterData")
	int32 Exp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CharacterData")
	FString AssetPath;
};
