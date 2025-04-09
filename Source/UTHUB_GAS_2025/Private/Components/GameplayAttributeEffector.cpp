#include "Components/GameplayAttributeEffector.h"

#include "CoreAttributeSet.h"
#include "GameplayEffectExtension.h"

void UGameplayAttributeEffector::ApplyAttributeEffector(const FOnAttributeChangeData& InChangeData)
{
	RecieveApplyAttributeEffector(InChangeData.GEModData->Target.GetOwner(), InChangeData.NewValue, InChangeData.OldValue);
}
