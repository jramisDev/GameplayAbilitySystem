#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayAttributeEffector.generated.h"

struct FOnAttributeChangeData;

UCLASS(Blueprintable, BlueprintType)
class UTHUB_GAS_2025_API UGameplayAttributeEffector : public UObject
{
	GENERATED_BODY()

public:

	void ApplyAttributeEffector(const FOnAttributeChangeData& InChangeData);

	UFUNCTION(BlueprintImplementableEvent)
	void RecieveApplyAttributeEffector(AActor* InActor);
};
