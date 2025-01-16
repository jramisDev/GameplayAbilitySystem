#include "UTHUB_ASC.h"

UUTHUB_ASC::UUTHUB_ASC()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UUTHUB_ASC::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo(GetOwner(), GetOwner());
}

void UUTHUB_ASC::InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
{
	Super::InitAbilityActorInfo(InOwnerActor, InAvatarActor);
	//INIT EFFECT
	//INIT ATTRIBS
	//INIT SKILLS
}

void UUTHUB_ASC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

