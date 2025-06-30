// Copyright by MF

#pragma once

#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "WarriorStructTypes.generated.h"

class UWarriorHeroLinkedAnimLayer;
class UHeroGameplayAbility;
class UInputMappingContext;

USTRUCT(BlueprintType)
struct FWarriorHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UHeroGameplayAbility> AbilityToGrant;

	bool IsValid() const;
	
};

USTRUCT(BlueprintType)
struct FWarriorHeroWeaponData
{
	GENERATED_BODY()

	//The anim layer will link to the hero character which it will perform when equipping this weapon.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UWarriorHeroLinkedAnimLayer> WeaponAnimLayerToLink;

	//The input mapping context that will be used when the weapon is equipped.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> WeaponInputMappingContext;

	//The abilities that will be granted to the hero character when the weapon is equipped.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "InputTag"))
	TArray<FWarriorHeroAbilitySet> DefaultWeaponAbilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FScalableFloat WeaponBaseDamage;
};
