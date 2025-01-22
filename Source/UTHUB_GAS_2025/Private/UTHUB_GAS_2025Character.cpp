#include "UTHUB_GAS_2025Character.h"

#include "AbilitySystemComponent.h"
#include "GameplayBaseStateTags.h"
#include "GameplayStatesManager.h"
#include "UTHUB_ASC.h"
#include "Attacks/AttackBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/DecalComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "GameFramework/PlayerState.h"

AUTHUB_GAS_2025Character::AUTHUB_GAS_2025Character()
{
	ASC = CreateDefaultSubobject<UUTHUB_ASC>("ASC");
	
	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AUTHUB_GAS_2025Character::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

UAbilitySystemComponent* AUTHUB_GAS_2025Character::GetAbilitySystemComponent() const
{
	return ASC;
}

void AUTHUB_GAS_2025Character::BeginPlay()
{
	Super::BeginPlay();

	//GameplayStates.AddTag(FGameplayStatesManager::Get().Tag_InteractEnabled);

	check(CharacterStates)
	GameplayStates.AddTag(CharacterStates->Tag_Alive);

	if(CharacterData)
	{
		TArray<FCharacterAttributes*> OutData;
		CharacterData->GetAllRows(TEXT(""), OutData);

		if(!OutData.IsEmpty())
		{
			FCharacterAttributes** Attr = OutData.FindByPredicate([this](FCharacterAttributes* Row)
			{
				return Row->CharacterClassTag.MatchesTag(CharacterClassTag);
			});
			
			if(Attr) CharacterAttributes = *Attr;
		}

	}
	
}

void AUTHUB_GAS_2025Character::Jump()
{
	Super::Jump();

	GameplayStates.RemoveTag(FGameplayStatesManager::Get().Tag_InteractEnabled);
}

void AUTHUB_GAS_2025Character::Attack()
{
	if(const TSubclassOf<UAttackBase> PrimaryAttack = CharacterAttributes->PrimaryAttack)
	{
		PrimaryAttack->GetDefaultObject<UAttackBase>()->TryAttack(GetOwner());
	}
}
