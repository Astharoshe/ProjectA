// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectA.h"
#include "Components/ActorComponent.h"
#include "CharacterStateComponent.generated.h"

struct FCharacterData;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTA_API UCharacterStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCharacterStateComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:	
	void SetLevel(int32 _Level);
	void SetDamage(float _Damage);
	float GetDamage();

	void SetHP(float _HP);
	float GetHPRatio();
	
protected:
	FCharacterData* m_StateData;

	UPROPERTY(EditInstanceOnly, Category=State)
	int32 m_Level;

	UPROPERTY(Transient, VisibleInstanceOnly, Category=State)
	float m_CurrentHP;
		
};
