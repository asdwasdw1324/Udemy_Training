// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

class AWarriorHeroWeapon;
/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()

public:
	//Get hero carried weapon class by calling the parent function, then make a cast to AWarriorHeroWeapon
	//If the cast is successful, return the weapon, otherwise return nullptr
	UFUNCTION(blueprintCallable, Category="Warrior|Combat")
	AWarriorHeroWeapon* GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const;
};
