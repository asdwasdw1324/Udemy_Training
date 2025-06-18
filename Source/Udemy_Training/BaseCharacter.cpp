// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "BaseAbilitySystemComponent.h"
#include "BaseAttributeSet.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	CharacterBaseAbilitySystemComponent = CreateDefaultSubobject<UBaseAbilitySystemComponent>(TEXT("CharacterAbilitySystemComponent"));

	CharacterAttributeSet = CreateDefaultSubobject<UBaseAttributeSet>(TEXT("CharacterAttributeSet"));
	
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	// Call the ForceInLined Getter function to get the AbilitySystemComponent
	return GetWarriorAbilitySystemComponent();
}

UPawnCombatComponent* ABaseCharacter::GetPawnCombatComponent() const
{
	return nullptr;
}

void ABaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Initialize the AbilitySystemComponent with the owner and avatar
	if (CharacterBaseAbilitySystemComponent)
	{
		CharacterBaseAbilitySystemComponent->InitAbilityActorInfo(this, this);
		
		ensureMsgf(!CharacterStartUpData.IsNull(), TEXT("CharacterStartUpData is not assigned to %s!"), *GetName());
		
	}
}


