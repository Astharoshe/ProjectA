// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "PlayerCharacterMovementComponent.h"
#include "PlayerCameraComponent.h"

APlayerCharacter::APlayerCharacter(const FObjectInitializer& _ObjectInitializer)
	: Super(_ObjectInitializer.SetDefaultSubobjectClass<UPlayerCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	InitCameraComponent();
}


void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacter::InitCameraComponent()
{
	m_pSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	m_pSpringArm->SetupAttachment(GetCapsuleComponent());
	m_pSpringArm->TargetArmLength = 400.0f;
	m_pSpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	m_pCamera = CreateDefaultSubobject<UPlayerCameraComponent>(TEXT("PLAYERCAMERA"));
	m_pCamera->SetupAttachment(m_pSpringArm);
}

void APlayerCharacter::MoveForward(float _AxisValue)
{
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), _AxisValue);
}

void APlayerCharacter::MoveRight(float _AxisValue)
{
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), _AxisValue);
}

void APlayerCharacter::LookUp(float _AxisValue)
{
	AddControllerPitchInput(_AxisValue);
}

void APlayerCharacter::Turn(float _AxisValue)
{
	AddControllerYawInput(_AxisValue);
}

void APlayerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

}
