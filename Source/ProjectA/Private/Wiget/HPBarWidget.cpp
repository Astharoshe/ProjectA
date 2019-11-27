// Fill out your copyright notice in the Description page of Project Settings.


#include "HPBarWidget.h"
#include "Components/ProgressBar.h"


void UHPBarWidget::NativeConstruct()
{
	Super::NativeConstruct();
	HPProgress = Cast<UProgressBar>(GetWidgetFromName(TEXT("HP_Bar")));
	CHECKASSERT(nullptr != HPProgress);

	UpdateWidget();
}

void UHPBarWidget::UpdateWidget()
{
	if (nullptr == HPProgress)
	{
		return;
	}

	HPProgress->SetPercent(0);
}
