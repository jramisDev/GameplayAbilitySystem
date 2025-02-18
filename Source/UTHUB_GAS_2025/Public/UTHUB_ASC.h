#pragma once

#include "AbilitySystemComponent.h"
#include "CoreMinimal.h"
#include "CoreAttributeSet.h"
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
	void InitializeAttributesFromEffects();

public:
	
	virtual void InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor) override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	void ApplyGameplayEffect(const TSubclassOf<UGameplayEffect>& EffectClass);
private:

	template<typename AttrSetType>
	AttrSetType* GetAttributeSetFromOwner() const;
};

template <typename AttrSetType>
AttrSetType* UUTHUB_ASC::GetAttributeSetFromOwner() const
{
	if(!GetOwner()) return nullptr;
	
	TArray<UObject*> OutSubobjects;
	GetOwner()->GetDefaultSubobjects(OutSubobjects);

	UObject** AttributeSet = OutSubobjects.FindByPredicate([](const UObject* Obj)
	{
		return Obj->IsA(AttrSetType::StaticClass());
	});

	if(!AttributeSet) return nullptr;

	return Cast<AttrSetType>(*AttributeSet);
}
