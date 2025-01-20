#include "Interactive.h"

#include "GameplayStatesManager.h"
#include "UTHUB_GAS_2025Character.h"

AInteractive::AInteractive()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AInteractive::CheckTagCondition(AActor* TagOwner)
{
	if(const AUTHUB_GAS_2025Character* GasCharacter = Cast<AUTHUB_GAS_2025Character>(TagOwner))
	{
		//FGameplayTag InteractiveTag = FGameplayTag::RequestGameplayTag(TEXT("Gameplay.States.CanInteract"));
		FGameplayTag InteractiveTag = FGameplayStatesManager::Get().Tag_InteractEnabled;
		if(!GasCharacter->GameplayStates.HasTag(InteractiveTag)) return;
		
		
		if(GasCharacter->ActiveEventTag.IsValid())
		{
			if(GasCharacter->ActiveEventTag.MatchesTag(ConditionTag))
			{
				ExecuteAction();				
			}
		}
	}
}

void AInteractive::BeginPlay()
{
	Super::BeginPlay();
}

void AInteractive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

