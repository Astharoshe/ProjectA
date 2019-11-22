#pragma once
#include "ProjectA.h"
#include "Engine/DataTable.h"
#include "BaseData.generated.h"



USTRUCT()
struct PROJECTA_API FBaseData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
	
public:
	FBaseData() {}
};