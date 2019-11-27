// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
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
