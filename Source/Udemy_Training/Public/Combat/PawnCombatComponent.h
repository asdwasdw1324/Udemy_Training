// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "PawnExtensionComponentBase.h"
#include "GameplayTagContainer.h"
#include "PawnCombatComponent.generated.h"

//Pawn combat component to provide basic combat functionality for pawns
//Include register spawned weapon, get current equipped weapon, get carried weapon by tag, etc.

class AWarriorBaseWeapon;

/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()

public:
	//After registering weapon by tag, it will be added to CharacterCarriedWeaponMap
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorBaseWeapon* InWeaponToRegister, bool bRegisterAsEquippedWeapon = false);

	//Below are functions to get carried weapon by tag from CharacterCarriedWeaponMap
	UFUNCTION(BlueprintCallable, Category = "Warrior|Combat")
	AWarriorBaseWeapon* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const;

	//Define a current equipped weapon tag and below function to get current equipped weapon from CharacterCarriedWeaponMap
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Warrior|Combat")
	FGameplayTag CurrentEquippedWeaponTag;

	UFUNCTION(Category = "Warrior|Combat")
	AWarriorBaseWeapon* GetCharacterCurrentEquippedWeapon() const;
	
	
private:
	//CharacterCarriedWeaponMap is a map to store all registered weapons by tag
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Warrior|Combat", meta = (AllowPrivateAccess = "true"))
	TMap<FGameplayTag, AWarriorBaseWeapon*> CharacterCarriedWeaponMap;
	
};
