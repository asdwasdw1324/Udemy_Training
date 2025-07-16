// Copyright by MF


#include "GameplayAbility/EnemyGameplayAbility.h"
#include "BaseEnemyCharacter.h"

ABaseEnemyCharacter* UEnemyGameplayAbility::GetBaseEnemyCharacterFromActorInfo()
{
	if (!CachedBaseEnemyCharacter.IsValid())
	{
		CachedBaseEnemyCharacter = Cast<ABaseEnemyCharacter>(GetAvatarActorFromActorInfo());
	}
	return CachedBaseEnemyCharacter.IsValid()? CachedBaseEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetBaseEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();	
}
