// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectA.h"
#include "Actor/BaseCharacter.h"
#include "PlayerCharacter.generated.h"

class UPlayerCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class PROJECTA_API APlayerCharacter : public ABaseCharacter
{
	//GENERATED_UCLASS_BODY()
	GENERATED_BODY()
	
public:
	APlayerCharacter(const FObjectInitializer& _ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//
	void InitCameraComponent();


	virtual void MoveForward(float _AxisValue) override;
	virtual void MoveRight(float _AxisValue) override;
	virtual void LookUp(float _AxisValue) override;
	virtual void Turn(float _AxisValue) override;

public:
	virtual void PostInitializeComponents() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual void PossessedBy(AController* NewController) override;


protected:

	UPROPERTY(VisibleAnywhere, Category=Camera)
	USpringArmComponent* m_pSpringArm;

	UPROPERTY(VisibleAnywhere, Category=Camera)
	UPlayerCameraComponent* m_pCamera;


};
