// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectAPlayerState.h"
#include "ProjectASaveGame.h"


AProjectAPlayerState::AProjectAPlayerState() :
	SaveSlotName(TEXT("Player"))
{

}

void AProjectAPlayerState::InitPlayerData()
{
	auto SaveGameData = Cast<UProjectASaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0));
	if (nullptr == SaveGameData)
	{
		SaveGameData = GetMutableDefault<UProjectASaveGame>();
	}


}

void AProjectAPlayerState::SavePlayerData()
{
	UProjectASaveGame* NewSaveData = NewObject<UProjectASaveGame>();

	if (!UGameplayStatics::SaveGameToSlot(NewSaveData, SaveSlotName, 0))
	{
		PROJECT_LOG(Error, TEXT("Save Error"));
	}
}
