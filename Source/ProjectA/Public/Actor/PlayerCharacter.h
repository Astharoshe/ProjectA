// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectA.h"
#include "Actor/BaseCharacter.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTA_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void PostInitializeComponents() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void PossessedBy(AController* NewController) override;
};
