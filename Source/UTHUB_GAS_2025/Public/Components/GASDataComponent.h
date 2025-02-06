#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GASDataComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UTHUB_GAS_2025_API UGASDataComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGASDataComponent();

	UPROPERTY(EditAnywhere, Category="Data", meta=(AllowPrivateAccess = true ))
	UDataTable* DT_CoreStats;	
};
