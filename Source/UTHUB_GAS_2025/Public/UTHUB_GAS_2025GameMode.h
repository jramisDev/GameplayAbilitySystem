// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/GameModeBase.h"
#include "UTHUB_GAS_2025GameMode.generated.h"

UCLASS(minimalapi)
class AUTHUB_GAS_2025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUTHUB_GAS_2025GameMode();

	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer) override;

	void CharacterIsAllowedToInteract(FGameplayTag GameplayTag, int Count);

private:
	TArray<class UGameStates*> GameStates;
};



