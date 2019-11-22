#pragma once
#include "BaseData.h"
#include "SkillData.generated.h"


USTRUCT(BlueprintType)
struct  PROJECTA_API FSkillData : public FBaseData
{
	GENERATED_USTRUCT_BODY()
	
public:
	FSkillData();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SkillData")
	int32 Index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SkillData")
	FString Name;

	
};