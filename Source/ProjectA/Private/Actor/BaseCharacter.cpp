// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "ProjectAGameInstance.h"
#include "Components/WidgetComponent.h"
#include "ProjectAAIController.h"
#include "ProjectAPlayerController.h"
#include "CharacterStateComponent.h"


// Sets default values
//ABaseCharacter::ABaseCharacter()
//{
// 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//}

ABaseCharacter::ABaseCharacter(const FObjectInitializer& _ObjectInitializer)
	: Super(_ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	InitController();
	OnAssetLoadInit();
}

void ABaseCharacter::InitController()
{
	IsPlayer = IsPlayerControlled();
	if (IsPlayer)
	{
		PlayerController = Cast<AProjectAPlayerController>(GetController());
		CHECKASSERT(nullptr != PlayerController);
	}
	else
	{
		AIController = Cast<AProjectAAIController>(GetController());
		CHECKASSERT(nullptr != AIController);
	}
}

void ABaseCharacter::InitAIComponent()
{
	AIControllerClass = AProjectAAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void ABaseCharacter::InitWidgetComponent()
{
	HPBarWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HPBARWIDGET"));
	HPBarWidgetComponent->SetupAttachment(GetMesh());
	HPBarWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	HPBarWidgetComponent->SetHiddenInGame(true);

	ConstructorHelpers::FClassFinder<UUserWidget> UI_HPBAR(TEXT(""));
	CHECKASSERT(UI_HPBAR.Succeeded());
	
	HPBarWidgetComponent->SetWidgetClass(UI_HPBAR.Class);
	//HPBarWidgetComponent->SetDrawSize(FVector2D()
}

void ABaseCharacter::InitStateComponent()
{
	CharacterStateComponent = CreateDefaultSubobject<UCharacterStateComponent>(TEXT("STATE"));
	
}

void ABaseCharacter::OnAssetLoadInit()
{
	//AssetToLoad = 

	auto GameInstance = Cast<UProjectAGameInstance>(GetGameInstance());
	if (nullptr == GameInstance)
	{
		return;
	}

	auto StreamMgr = GameInstance->GetStreamableMgr();
	CHECKASSERT(nullptr != StreamMgr);
	
	AssetStreamingHandle = StreamMgr->RequestAsyncLoad(AssetToLoad, FStreamableDelegate::CreateUObject(this, &ABaseCharacter::OnAssetLoadCompleted));
	//SetCharacterState(ECharacterState::LOADING);
}

void ABaseCharacter::OnAssetLoadCompleted()
{
	AssetStreamingHandle->ReleaseHandle();
	TSoftObjectPtr<USkeletalMesh> LoadMesh(AssetToLoad);
	CHECKASSERT(LoadMesh.IsValid());

	GetMesh()->SetSkeletalMesh(LoadMesh.Get());
	//SetCharacterState(ECharacterState::READY);
}

void ABaseCharacter::MoveForward(float _AxisValue)
{
	// Actor 기준 이동
	//AddMovementInput(GetActorForwardVector(), _AxisValue);

	//카메라 기준 이동
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), _AxisValue);
}

void ABaseCharacter::MoveRight(float _AxisValue)
{
	// Actor 기준 이동
	//AddMovementInput(GetActorRightVector(), _AxisValue);

	//카메라 기준 이동
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), _AxisValue);
}

void ABaseCharacter::LookUp(float _AxisValue)
{
	AddControllerPitchInput(_AxisValue);
}

void ABaseCharacter::Turn(float _AxisValue)
{
	AddControllerYawInput(_AxisValue);
}

void ABaseCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* _PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(_PlayerInputComponent);
	_PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ABaseCharacter::MoveForward);
	_PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ABaseCharacter::MoveRight);
	_PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ABaseCharacter::LookUp);
	_PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ABaseCharacter::Turn);
}

