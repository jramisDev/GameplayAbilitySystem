#include "Interactive.h"

#include "GameplayStatesManager.h"
#include "UTHUB_GAS_2025Character.h"

AInteractive::AInteractive()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AInteractive::CheckTagCondition(AActor* TagOwner)
{

	if(UUTHUB_ASC* ASC = TagOwner->FindComponentByClass<UUTHUB_ASC>())
	{
		ASC->AddLooseGameplayTag(ConditionTag);
	}
	
	// if(IGameplayTagAssetInterface* TagAsssetInterface = Cast<IGameplayTagAssetInterface>(TagOwner))
	// {
	// 	FGameplayTagContainer CharacterTags;
	// 	TagAsssetInterface->GetOwnedGameplayTags(CharacterTags);
	//
	// 	if(!CharacterTags.HasTag(FGameplayStatesManager::Get().Tag_InteractEnabled)) return;
	// 	
	// 	if(CharacterTags.HasTag(ConditionTag))
	// 	{
	// 		ExecuteAction();
	// 	}
	// }
}

void AInteractive::BeginPlay()
{
	Super::BeginPlay();
}

void AInteractive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

