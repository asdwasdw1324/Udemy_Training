// Copyright by MF


#include "WarriorStructTypes.h"
#include "GameplayAbility/HeroGameplayAbility.h"

bool FWarriorHeroAbilitySet::IsValid() const
{
	return InputTag.IsValid() && AbilityToGrant;
}


