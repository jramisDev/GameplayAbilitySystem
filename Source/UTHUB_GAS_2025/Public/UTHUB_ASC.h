#pragma once

#include "AbilitySystemComponent.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UTHUB_ASC.generated.h"

UINTERFACE(NotBlueprintable)
class UGameplayTagCustomInterface : public UGameplayTagAssetInterface
{
	GENERATED_BODY()
};

class IGameplayTagCustomInterface : public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable, Category = "GameplayTags")
	virtual void AddTags(const FGameplayTag& InTag) = 0;
	
	UFUNCTION(BlueprintCallable, Category = "GameplayTags")
	virtual void RemoveTags(FGameplayTag& InTag) = 0;
	
};


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UTHUB_GAS_2025_API UUTHUB_ASC : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UUTHUB_ASC();
	
protected:
	virtual void BeginPlay() override;
	void InitializeAttributes(const AActor* InOwnerActor) const;

public:
	
	virtual void InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor) override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
