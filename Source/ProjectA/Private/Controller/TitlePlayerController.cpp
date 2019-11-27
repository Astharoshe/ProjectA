// Fill out your copyright notice in the Description page of Project Settings.


#include "TitlePlayerController.h"
#include "Blueprint/UserWidget.h"
#include "TitleWidget.h"

void ATitlePlayerController::BeginPlay()
{
	Super::BeginPlay();

	CHECKASSERT(nullptr != UIWidgetClass);

	UIWigetInstance = CreateWidget<UUserWidget>(this, UIWidgetClass);
	CHECKASSERT(nullptr != UIWigetInstance);
	UIWigetInstance->AddToViewport();


	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(UIWigetInstance->GetCachedWidget());
	SetInputMode(InputMode);

	bShowMouseCursor = true;
}