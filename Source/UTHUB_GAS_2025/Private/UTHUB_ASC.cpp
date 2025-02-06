#include "UTHUB_ASC.h"

#include "CoreAttributeSet.h"
#include "Components/GASDataComponent.h"

// void IGameplayTagCustomAssetInterface::AddTags(const FGameplayTag& InTag)
// {
// 	FGameplayTagContainer TagContainer;
// 	GetOwnedGameplayTags(TagContainer);
//
// 	TagContainer.AddTag(InTag);
// }
//
// void IGameplayTagCustomAssetInterface::RemoveTags(FGameplayTag& InTag)
// {
// 	FGameplayTagContainer TagContainer;
// 	GetOwnedGameplayTags(TagContainer);
//
// 	TagContainer.RemoveTag(InTag);
// }

UUTHUB_ASC::UUTHUB_ASC()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UUTHUB_ASC::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo(GetOwner(), GetOwner());
}

void UUTHUB_ASC::InitializeAttributes(const AActor* InOwnerActor) const
{
	if(UGASDataComponent* DataComponent = InOwnerActor->FindComponentByClass<UGASDataComponent>())
	{
		if(DataComponent->DT_CoreStats)
		{
			auto InitializeAttribute = [this](const FName& RowName, const FGameplayCoreAttribute& Row)
			{
				UCoreAttributeSet* CoreSet = const_cast<UCoreAttributeSet*>(GetSet<UCoreAttributeSet>());

				float NewValue = Row.AttributeBaseValue;
				Row.Attribute.SetNumericValueChecked(NewValue, CoreSet);
			};
		
			DataComponent->DT_CoreStats->ForeachRow<FGameplayCoreAttribute>(TEXT(""), InitializeAttribute);
		}		
	}
}

void UUTHUB_ASC::InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
{
	Super::InitAbilityActorInfo(InOwnerActor, InAvatarActor);

	InitializeAttributes(InOwnerActor);
	//INIT EFFECT
	//INIT ATTRIBS
	//INIT SKILLS
}

void UUTHUB_ASC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

 