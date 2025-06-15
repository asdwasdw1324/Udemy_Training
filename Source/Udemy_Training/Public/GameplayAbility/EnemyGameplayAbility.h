// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "BaseGameplayAbility.h"
#include "EnemyGameplayAbility.generated.h"

class ABaseEnemyCharacter;
class UEnemyCombatComponent;

/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API UEnemyGameplayAbility : public UBaseGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Enemy|Ability")
	ABaseEnemyCharacter* GetBaseEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Enemy|Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<ABaseEnemyCharacter> CachedBaseEnemyCharacter;
	
};
