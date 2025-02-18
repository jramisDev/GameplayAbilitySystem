// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "UTHUB_ASC.h"
#include "UTHUB_GAS_2025Character.generated.h"

class UCoreAttributeSet;
class UAttackBase;
class UGameplayBaseStateTags;

USTRUCT()
struct FCharacterAttributes : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)	FGameplayTag CharacterClassTag;
	UPROPERTY(EditAnywhere)	float Health;
	UPROPERTY(EditAnywhere)	float AttackStrength;
	UPROPERTY(EditAnywhere)	float Speed;
	UPROPERTY(EditAnywhere)	UAnimMontage* AttackAnimation;
};

UCLASS(Blueprintable)
class AUTHUB_GAS_2025Character : public ACharacter, public IAbilitySystemInterface, public IGameplayTagCustomInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true ))
	FGameplayTag CharacterClassTag;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true ))
	FCharacterAttributes* CharacterAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true ))
	UDataTable* CharacterData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = true ))
	TSubclassOf<UGameplayEffect> SampleEffect;
	
	UPROPERTY()
	UCoreAttributeSet* CoreAttributeSet;
	
public:
	AUTHUB_GAS_2025Character();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag ActiveEventTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTagContainer GameplayStates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UGameplayBaseStateTags* CharacterStates;

	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;
	
	virtual void AddTags(const FGameplayTag& InTag) override;
	virtual void RemoveTags(FGameplayTag& InTag) override;

	UFUNCTION(CallInEditor)
	void ApplyGameplayEffects();

protected:
	virtual void BeginPlay() override;
	virtual void Jump() override;
	virtual void PostInitializeComponents() override;

private:
	
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
	class UUTHUB_ASC* ASC;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Gameplay, meta = (AllowPrivateAccess = "true"))
	class UGASDataComponent* GASDataComponent;
	
	void InitializeCharacter();

	void SetupAttributeCallbacks();
	
};

