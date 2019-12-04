// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectAGameModeBase.h"
#include "BaseCharacter.h"
#include "ProjectAGameState.h"
#include "ProjectAPlayerState.h"
#include "ProjectAPlayerController.h"
#include "ProjectAAIController.h"


AProjectAGameModeBase::AProjectAGameModeBase()
{
	// �⺻ Class ����
	//Pawn
	DefaultPawnClass = ABaseCharacter::StaticClass();

	// Control
	PlayerControllerClass = AProjectAPlayerController::StaticClass();

	// State
	PlayerStateClass = AProjectAPlayerState::StaticClass();

	// GameState
	GameStateClass = AProjectAGameState::StaticClass();
}

void AProjectAGameModeBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	m_GameState = Cast<AProjectAGameState>(GameState);
}

void AProjectAGameModeBase::PostLogin(APlayerController* _NewPlayer)
{
	Super::PostLogin(_NewPlayer);
	
	auto PlayerState = Cast<AProjectAPlayerState>(_NewPlayer->PlayerState);
	CHECKASSERT(nullptr != PlayerState);
	// ���� ������ Ȯ��
	PlayerState->InitPlayerData();
}
