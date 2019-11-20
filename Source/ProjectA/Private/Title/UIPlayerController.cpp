// Fill out your copyright notice in the Description page of Project Settings.


#include "UIPlayerController.h"
#include "Blueprint/UserWidget.h"


void AUIPlayerController::BeginPlay()
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