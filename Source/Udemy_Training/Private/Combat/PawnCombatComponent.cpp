// Copyright by MF


#include "Combat/PawnCombatComponent.h"
#include "WarriorBaseWeapon.h"
#include "Components/BoxComponent.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister, AWarriorBaseWeapon* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister), TEXT("Weapon with the same tag: %s already registered!"), *InWeaponTagToRegister.ToString());
	checkf(InWeaponToRegister, TEXT("WeaponTag: %s to register is nullptr!"), *InWeaponTagToRegister.ToString());

	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister, InWeaponToRegister);

	InWeaponToRegister->OnWeaponHitTarget.BindUObject(this, &UPawnCombatComponent::OnHitTargetActor);
	InWeaponToRegister->OnWeaponPulledFromTarget.BindUObject(this, &UPawnCombatComponent::OnWeaponPulledFromTargetActor);
	
	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag = InWeaponTagToRegister;
		//Debug::Print(FString::Printf(TEXT("Weapon with the tag: %s has been registered as equipped weapon!"), *InWeaponTagToRegister.ToString()));
	}
	
}

AWarriorBaseWeapon* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if (auto FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}
	return nullptr;
}

//Call the above function to get the current equipped weapon
AWarriorBaseWeapon* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}
	return GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}

void UPawnCombatComponent::ToggleWeaponCollision(bool bShouldEnable, EToggleDamageType ToggleDamageType)
{
	if (ToggleDamageType == EToggleDamageType::CurrentEquippedWeapon)
	{
		AWarriorBaseWeapon* WeaponToToggle = GetCharacterCurrentEquippedWeapon();

		check(WeaponToToggle);

		if (bShouldEnable)
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			//Debug::Print(FString::Printf(TEXT("Weapon collision enabled for the weapon: %s"), *WeaponToToggle->GetName()), FColor::Green);
		}
		else
		{
			WeaponToToggle->GetWeaponCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

			OverlappedActors.Empty();
			//Debug::Print(FString::Printf(TEXT("Weapon collision disabled for the weapon: %s"), *WeaponToToggle->GetName()), FColor::Red);
		}
	}
	
}

void UPawnCombatComponent::OnHitTargetActor(AActor* HitActor)
{
}

void UPawnCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
}
