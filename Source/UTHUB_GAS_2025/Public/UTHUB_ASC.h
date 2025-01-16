#pragma once

#include "AbilitySystemComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UTHUB_ASC.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UTHUB_GAS_2025_API UUTHUB_ASC : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UUTHUB_ASC();

	virtual void InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor) override;
	
protected:
	virtual void BeginPlay() override;


public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
