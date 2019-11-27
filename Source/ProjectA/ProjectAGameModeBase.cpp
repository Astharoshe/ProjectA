// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectAGameModeBase.h"
#include "BaseCharacter.h"

AProjectAGameModeBase::AProjectAGameModeBase()
{
	//
	DefaultPawnClass = ABaseCharacter::StaticClass();

	//PlayerControllerClass;

	//PlayerStateClass = ;

	//GameStateClass = ;
}

void AProjectAGameModeBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AProjectAGameModeBase::PostLogin(APlayerController* _NewPlayer)
{
	Super::PostLogin(_NewPlayer);
	
}
