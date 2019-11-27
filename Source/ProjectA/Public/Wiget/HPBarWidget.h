// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectA.h"
#include "Blueprint/UserWidget.h"
#include "HPBarWidget.generated.h"

class UCharacterStateComponent;
class UProgressBar;

/**
 * 
 */
UCLASS()
class PROJECTA_API UHPBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
protected:
	//
	virtual void NativeConstruct() override;
	
	//
	void UpdateWidget();

private:
	TWeakObjectPtr<UCharacterStateComponent> StateComponent;

	UPROPERTY()
	UProgressBar* HPProgress;
};
