// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterStateComponent.h"
#include "ProjectAGameInstance.h"
#include "CharacterData.h"


// Sets default values for this component's properties
UCharacterStateComponent::UCharacterStateComponent() : m_Level(1)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
	// ComoponentInitialize() »ç¿ë
	bWantsInitializeComponent = true;
}


// Called when the game starts
void UCharacterStateComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UCharacterStateComponent::InitializeComponent()
{
	Super::InitializeComponent();
	SetLevel(m_Level);
}

void UCharacterStateComponent::SetLevel(int32 _Level)
{
	//PROJECT_LOG(Warning, TEXT("SetLevel %d"), _Level);
	//auto GameInstance = Cast<UProjectAGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));

	//CHECKASSERT(nullptr != GameInstance);
	//CurrentStateData = GameInstance->GetCharacterData(_Level);
	//if (nullptr != CurrentStateData)
	//{
	//	Level = _Level;
	//	SetHP(CurrentStateData->MaxHP);
	//}
	//else
	//{
	//	PROJECT_LOG(Error, TEXT("Level %d No Data"), _Level);
	//}
}

void UCharacterStateComponent::SetDamage(float _Damage)
{
	//CHECKASSERT(nullptr != CurrentStateData);
	//SetHP(FMath::Clamp<float>(CurrentHP - _Damage, 0.0f, CurrentStateData->MaxHP));
}

float UCharacterStateComponent::GetDamage()
{
	//ABCHECK(nullptr != CurrentStateData, 0.0f);
	//return CurrentStateData->Attack;
	return 0.0f;
}

void UCharacterStateComponent::SetHP(float _HP)
{
	//CurrentHP = _HP;
	////OnHPChanged.Broadcast();
	//if (CurrentHP < KINDA_SMALL_NUMBER)
	//{
	//	CurrentHP = 0.f;
	//	//OnHPIsZeoro.Broadcast();
	//}
}

float UCharacterStateComponent::GetHPRatio()
{
	//CHECKASSERT(nullptr != CurrentStateData, 0.0f);
	//float MaxHP = CurrentStateData->MaxHP;
	//return (MaxHP < KINDA_SMALL_NUMBER) ? 0.0f : (CurrentHP / MaxHP);

	return 0.0f;
}

