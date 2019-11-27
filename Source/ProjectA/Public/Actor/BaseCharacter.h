// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectA.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


class UInputComponent;
class UCharacterStateComponent;
class UWidgetComponent;

UCLASS()
class PROJECTA_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//
	virtual void OnAssetLoadInit();
	virtual void OnAssetLoadCompleted();

public:	

	virtual void PostInitializeComponents() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(VisibleAnywhere, Category = State)
	UCharacterStateComponent* CharacterStateComponent;


	UPROPERTY(VisibleAnywhere, Category = UI)
	UWidgetComponent* HPBarWidgetComponent;
};
