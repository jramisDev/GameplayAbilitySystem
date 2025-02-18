﻿#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeSet.h"
#include "GASDataComponent.generated.h"


struct FGameplayAttribute;
class UGameplayAttributeEffector;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UTHUB_GAS_2025_API UGASDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGASDataComponent();

	UPROPERTY(EditAnywhere, Category="Data", meta=(AllowPrivateAccess = true ))
	UDataTable* DT_CoreStats;

	UPROPERTY(EditAnywhere, Category="Data", meta=(AllowPrivateAccess = true ))
	TArray<TSubclassOf<class UGameplayEffect>> AttributeInitializers;

	UPROPERTY(EditAnywhere, Category="Data", meta=(AllowPrivateAccess = true ))
	TMap<FGameplayAttribute, TSubclassOf<UGameplayAttributeEffector>> AttributeEffectors;
};
