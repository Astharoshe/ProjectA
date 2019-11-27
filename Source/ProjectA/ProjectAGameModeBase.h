// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectA.h"
#include "GameFramework/GameModeBase.h"
#include "ProjectAGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTA_API AProjectAGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AProjectAGameModeBase();

	//
	virtual void PostInitializeComponents() override;
	
	//
	virtual void PostLogin(APlayerController* _NewPlayer) override;

private:


};
