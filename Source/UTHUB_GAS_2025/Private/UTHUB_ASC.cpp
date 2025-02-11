#include "UTHUB_ASC.h"

#include "CoreAttributeSet.h"
#include "Components/GASDataComponent.h"

UUTHUB_ASC::UUTHUB_ASC()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UUTHUB_ASC::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo(GetOwner(), GetOwner());
	InitializeAttributes(GetOwner());
}

void UUTHUB_ASC::InitializeAttributes(const AActor* InOwnerActor) const
{
	if(UCoreAttributeSet* CoreAttributes = GetAttributeSetFromOwner<UCoreAttributeSet>())
	{
		if(const UGASDataComponent* DataComponent = InOwnerActor->FindComponentByClass<UGASDataComponent>())
		{
			if(DataComponent->DT_CoreStats)
			{
				auto InitializeAttribute = [this, CoreAttributes](const FName& RowName, const FGameplayCoreAttribute& Row)
				{
					float NewValue = Row.AttributeBaseValue;
					Row.Attribute.SetNumericValueChecked(NewValue, CoreAttributes);
				};
		
				DataComponent->DT_CoreStats->ForeachRow<FGameplayCoreAttribute>(TEXT(""), InitializeAttribute);
			}		
		}
	}
}

void UUTHUB_ASC::InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
{
	Super::InitAbilityActorInfo(InOwnerActor, InAvatarActor);
}

void UUTHUB_ASC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
 