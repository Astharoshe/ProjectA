// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectA.h"
#include "GameFramework/PlayerController.h"
#include "TitlePlayerController.generated.h"

class UUserWidget;
/**
 * 
 */
UCLASS()
class PROJECTA_API ATitlePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<UUserWidget> UIWidgetClass;

	UPROPERTY()
	class UUserWidget* UIWigetInstance;
	
};
