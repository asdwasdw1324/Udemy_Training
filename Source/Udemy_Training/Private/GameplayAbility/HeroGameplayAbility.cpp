// Copyright by MF


#include "GameplayAbility/HeroGameplayAbility.h"
#include "BaseHeroCharacter.h"
#include "HeroGameBase/HeroPlayerController.h"

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
		CachedHeroPlayerController = Cast<AHeroPlayerController>(CurrentActorInfo->PlayerController);
	}
	return CachedHeroPlayerController.IsValid() ? CachedHeroPlayerController.Get() : nullptr;
}

UHeroCombatComponent* UHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}
