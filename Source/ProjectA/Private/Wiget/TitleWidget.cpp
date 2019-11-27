// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleWidget.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

void UTitleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	BtnNewGame = Cast<UButton>(GetWidgetFromName(TEXT("Btn_NewGame")));
	CHECKASSERT(nullptr != BtnNewGame);

	BtnLoadGame = Cast<UButton>(GetWidgetFromName(TEXT("Btn_LoadGame")));
	CHECKASSERT(nullptr != BtnLoadGame);

	BtnExit = Cast<UButton>(GetWidgetFromName(TEXT("Btn_Exit")));
	CHECKASSERT(nullptr != BtnExit);
	BtnExit->OnClicked.AddDynamic(this, &UTitleWidget::OnBtnExitGame);
}

void UTitleWidget::OnBtnExitGame()
{
	UWorld* pWorld = GetWorld();

	UKismetSystemLibrary::QuitGame(pWorld, UGameplayStatics::GetPlayerController(pWorld, 0), EQuitPreference::Quit, false);

}
