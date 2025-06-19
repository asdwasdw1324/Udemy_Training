// Copyright by MF


#include "Combat/HeroCombatComponent.h"

#include "Items/WarriorHeroWeapon.h"
#include "DebugHelper.h"

AWarriorHeroWeapon* UHeroCombatComponent::GetHeroCarriedWeaponByTag(FGameplayTag InWeaponTag) const
{
	return Cast<AWarriorHeroWeapon>(GetCharacterCarriedWeaponByTag(InWeaponTag));
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	Debug::Print(FString::Printf(TEXT("Hit target actor: %s"), *HitActor->GetActorNameOrLabel()), FColor::Green);
}

void UHeroCombatComponent::OnWeaponPulledFromTargetActor(AActor* InteractedActor)
{
	Debug::Print(FString::Printf(TEXT("Weapon pulled from the target: %s"), *InteractedActor->GetActorNameOrLabel()), FColor::Red);
}
