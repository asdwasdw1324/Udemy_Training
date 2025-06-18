// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Interfaces/PawnCombatInterface.h"
#include "BaseCharacter.generated.h"

//BaseCharacter class to provide base functionality for all characters in the game.
//It implements the IAbilitySystemInterface interface to provide access to the ability system component.
//It also provides access to the attribute set and ability system component of the character.

class UBaseAttributeSet;
class UBaseAbilitySystemComponent;
class UDataAsset_StartUpDataBase;

UCLASS()
class UDEMY_TRAINING_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface, public IPawnCombatInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface.

	//~ Begin IPawnCombatInterface Interface.
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface.
	
protected:

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abiliytysystem")
	TObjectPtr<UBaseAttributeSet> CharacterAttributeSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abiliytysystem")
	TObjectPtr<UBaseAbilitySystemComponent> CharacterBaseAbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	// return the attribute set of this character
	FORCEINLINE UBaseAttributeSet* GetWarriorAttributeSet() const { return CharacterAttributeSet; }

	//return the ability system component of this character
	FORCEINLINE UBaseAbilitySystemComponent* GetWarriorAbilitySystemComponent() const { return CharacterBaseAbilitySystemComponent; }
	
};
