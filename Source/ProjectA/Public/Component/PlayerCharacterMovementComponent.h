// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTA_API UPlayerCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
	
public:
	virtual void InitializeComponent() override;
};
