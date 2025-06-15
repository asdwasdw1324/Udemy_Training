// Copyright by MF


#include "DataAsset/DataAsset_StartUpDataEnemyBase.h"
#include "BaseAbilitySystemComponent.h"
#include "GameplayAbility/EnemyGameplayAbility.h"

void UDataAsset_StartUpDataEnemyBase::GiveToAbilitySystemComponent(UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	if (!EnemyCombatAbilities.IsEmpty())
	{
		for (const auto& EnemyCombatAbilityClass : EnemyCombatAbilities)
		{
			if (!EnemyCombatAbilityClass) continue;

			FGameplayAbilitySpec AbilitySpec(EnemyCombatAbilityClass);
			AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
			AbilitySpec.Level = ApplyLevel;
			
			InASCToGive->GiveAbility(AbilitySpec);
		}
	}
	
}
