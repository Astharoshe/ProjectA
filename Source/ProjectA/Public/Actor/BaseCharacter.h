// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectA.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


class UInputComponent;
class UCharacterStateComponent;
class UWidgetComponent;
class AProjectAAIController;
class AProjectAPlayerController;

struct FStreamableHandle;

UCLASS()
class PROJECTA_API ABaseCharacter : public ACharacter
{
	/*
	FObjectInitializer를 사용해서 초기화 할 경우 
	방법1 
	GENERATED_UCLASS_BODY() 사용
    Cpp에 생성자 구현 
	Class::Class(const FObjectInitializer& _ObjectInitializer)
	: Super(_ObjectInitializer.SetDefaultSubobjectClass<UPlayerCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))

	방법2
	선언하고 사용
	*/
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	//ABaseCharacter();
	ABaseCharacter(const FObjectInitializer& _ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Controller 
	void InitController();

	void InitAIComponent();

	void InitWidgetComponent();

	void InitStateComponent();

	// Asset Load 
	virtual void OnAssetLoadInit();

	// Asset Load Complete
	virtual void OnAssetLoadCompleted();


	virtual void MoveForward(float _AxisValue);
	virtual void MoveRight(float _AxisValue);
	virtual void LookUp(float _AxisValue);
	virtual void Turn(float _AxisValue);


public:	

	virtual void PostInitializeComponents() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* _PlayerInputComponent) override;

protected:
	UPROPERTY(VisibleAnywhere, Category = State)
	UCharacterStateComponent* CharacterStateComponent;
	
	UPROPERTY(VisibleAnywhere, Category = UI)
	UWidgetComponent* HPBarWidgetComponent;

	// PlayerCheck
	UPROPERTY(Transient, VisibleInstanceOnly, BlueprintReadOnly, Category = State)
	bool IsPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = State)
	float DeadTimer;

	//UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack)
	//float AttackRange;

	//UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = Attack)
	//float AttackRadius;

	UPROPERTY()
	AProjectAAIController* AIController;

	UPROPERTY()
	AProjectAPlayerController* PlayerController;

	// Asset Path
	FSoftObjectPath AssetToLoad;

	// Asset Load Streaming
	TSharedPtr<FStreamableHandle> AssetStreamingHandle;
	
	// DeadTimer
	FTimerHandle DeadTimerHandle;
};
