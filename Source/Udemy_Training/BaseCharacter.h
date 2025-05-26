// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UBaseAttributeSet;
class UBaseAbilitySystemComponent;
class UDataAsset_StartUpDataBase;

UCLASS()
class UDEMY_TRAINING_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	//~ Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface Interface.

protected:

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abiliytysystem")
	UBaseAttributeSet* WarriorAttributeSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abiliytysystem")
	UBaseAbilitySystemComponent* WarriorAbilitySystemComponent;

	UPROPERTY(EditDefaultsOnly, Category = "CharacterData")
	TSoftObjectPtr<UDataAsset_StartUpDataBase> CharacterStartUpData;

public:
	// return the attribute set of this character
	FORCEINLINE UBaseAttributeSet* GetWarriorAttributeSet() const { return WarriorAttributeSet; }

	//return the ability system component of this character
	FORCEINLINE UBaseAbilitySystemComponent* GetWarriorAbilitySystemComponent() const { return WarriorAbilitySystemComponent; }
	
};
