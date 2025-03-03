﻿#include "LavaPool.h"

#include "UTHUB_ASC.h"
#include "Components/GameplayAttributeEffector.h"
#include "Components/GASDataComponent.h"

ALavaPool::ALavaPool()
{
	PrimaryActorTick.bCanEverTick = true;

	ASC = CreateDefaultSubobject<UUTHUB_ASC>("ASC");
	GASDataComponent = CreateDefaultSubobject<UGASDataComponent>(TEXT("GAS Data"));
}

UAbilitySystemComponent* ALavaPool::GetAbilitySystemComponent() const
{
	return ASC;
}

void ALavaPool::BeginPlay()
{
	Super::BeginPlay();
	
	SetupAttributeCallbacks();
}
void ALavaPool::SetupAttributeCallbacks()
{
	//for(auto AttributeEffectorsPair : GASDataComponent->AttributeEffectors)
	for(auto [Attribute, EffectorClass] : GASDataComponent->AttributeEffectors)
	{
		ASC->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(
			EffectorClass->GetDefaultObject<UGameplayAttributeEffector>(),
			&UGameplayAttributeEffector::ApplyAttributeEffector);
	}
}