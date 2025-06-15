// Copyright by MF


#include "GameplayAbility/HeroGameplayAbility.h"
#include "BaseHeroCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "HeroGameBase/HeroPlayerController.h"
#include "EnhancedPlayerInput.h"
#include "EnhancedInputComponent.h"

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

