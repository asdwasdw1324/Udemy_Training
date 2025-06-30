// Copyright by MF


#include "GameplayAbility/HeroGameplayAbility.h"
#include "BaseHeroCharacter.h"
#include "HeroGameBase/HeroPlayerController.h"
#include "BaseAbilitySystemComponent.h"
#include "BaseGameTags.h"

ABaseHeroCharacter* UHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedHeroCharacter.IsValid())
	{
		CachedHeroCharacter = Cast<ABaseHeroCharacter>(GetAvatarActorFromActorInfo());
	}

	return CachedHeroCharacter.IsValid() ? CachedHeroCharacter.Get() : nullptr;
}

AHeroPlayerController* UHeroGameplayAbility::GetHeroPlayerControllerFromActorInfo()
{
	if (!CachedHeroPlayerController.IsValid())
	{
		CachedHeroPlayerController = CastChecked<AHeroPlayerController>(CurrentActorInfo->PlayerController);
	}
	return CachedHeroPlayerController.IsValid() ? CachedHeroPlayerController.Get() : nullptr;
}

UHeroCombatComponent* UHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}

FGameplayEffectSpecHandle UHeroGameplayAbility::MakeHeroDamageEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass,
	float InWeaponBaseDamage, FGameplayTag InCurrentAttackTypeTag, int32 InUsedComboCount)
{
	check(EffectClass);

	FGameplayEffectContextHandle ContextHandle = GetBaseAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(),GetAvatarActorFromActorInfo());

	FGameplayEffectSpecHandle EffectSpecHandle = GetBaseAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(EffectClass, GetAbilityLevel(),ContextHandle);

	EffectSpecHandle.Data->SetSetByCallerMagnitude(WarriorGameplayTags::Shared_SetByCaller_BaseDamage, InWeaponBaseDamage);

	if (InCurrentAttackTypeTag.IsValid())
	{
		EffectSpecHandle.Data->SetSetByCallerMagnitude(InCurrentAttackTypeTag,InUsedComboCount);
	}

	return EffectSpecHandle;
}

