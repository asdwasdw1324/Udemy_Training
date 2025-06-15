// Copyright by MF


#include "DataAsset_StartUpDataBase.h"
#include "BaseAbilitySystemComponent.h"
#include "BaseGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	check(InASCToGive != nullptr);

	GrantAbilities(ActivateOnGivenAbilities, InASCToGive, ApplyLevel);
	GrantAbilities(ReactiveAbilities, InASCToGive, ApplyLevel);

	if (!StartupGameplayEffects.IsEmpty())
	{
		for (const auto& EffectClass : StartupGameplayEffects)
		{
			if (!EffectClass) continue;

			UGameplayEffect* EffectCDO = EffectClass->GetDefaultObject<UGameplayEffect>();
			InASCToGive->ApplyGameplayEffectToSelf(EffectCDO, ApplyLevel, InASCToGive->MakeEffectContext());
		}
	}
}

void UDataAsset_StartUpDataBase::GrantAbilities(const TArray<TSubclassOf<UBaseGameplayAbility>>& InAbilitiesToGive, UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;
	}

	for (const auto& Ability : InAbilitiesToGive)
	{
		if (!Ability) continue;

		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability);
		AbilitySpec.Level = ApplyLevel;
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		InASCToGive->GiveAbility(AbilitySpec);
		
	}
}
