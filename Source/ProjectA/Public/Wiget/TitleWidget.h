// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectA.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidget.generated.h"


class UButton;
/**
 * 
 */
UCLASS()
class PROJECTA_API UTitleWidget : public UUserWidget
{
	GENERATED_BODY()
	
	
	
protected:
	// Widget Init
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnBtnExitGame();

private:
	UPROPERTY()
	UButton* BtnNewGame;

	UPROPERTY()
	UButton* BtnLoadGame;

	UPROPERTY()
	UButton* BtnExit;
};
