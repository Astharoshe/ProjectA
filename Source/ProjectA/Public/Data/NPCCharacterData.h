#pragma once

#include "BaseData.h"
#include "NPCCharacterData.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct PROJECTA_API FNPCCharacterData : public FBaseData
{
	GENERATED_USTRUCT_BODY()

public:
	FNPCCharacterData();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CharacterData")
	int32 Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterData")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterData")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterData")
	int32 Exp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CharacterData")
	FString AssetPath;
};
