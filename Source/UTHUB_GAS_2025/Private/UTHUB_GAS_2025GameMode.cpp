// Copyright Epic Games, Inc. All Rights Reserved.

#include "UTHUB_GAS_2025GameMode.h"

#include "GameplayStatesManager.h"
#include "UTHUB_GAS_2025PlayerController.h"
#include "UObject/ConstructorHelpers.h"

AUTHUB_GAS_2025GameMode::AUTHUB_GAS_2025GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AUTHUB_GAS_2025PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void AUTHUB_GAS_2025GameMode::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	Super::HandleStartingNewPlayer_Implementation(NewPlayer);

	// const APawn* PlayerPawn = NewPlayer->GetPawn();
	// ensureMsgf(PlayerPawn, TEXT("%s - We don't have a proper pawn initialized yet... Oh boy"), ANSI_TO_TCHAR(__FUNCTION__));
	//
	// UUTHUB_ASC* ASC = PlayerPawn->FindComponentByClass<UUTHUB_ASC>();
	//
	// if(ASC)
	// {
	// 	auto& Delegate = ASC->RegisterGameplayTagEvent(FGameplayStatesManager::Get().Tag_InteractEnabled);
	// 	Delegate.AddUObject(this, &ThisClass::CharacterIsAllowedToInteract);
	// }		
}

void AUTHUB_GAS_2025GameMode::CharacterIsAllowedToInteract(FGameplayTag GameplayTag, int Count)
{
	// Cualquier operación relacionada con los estados del juego
	UE_LOG(LogTemp, Display, TEXT("Now I Can interact!!!"));
}
