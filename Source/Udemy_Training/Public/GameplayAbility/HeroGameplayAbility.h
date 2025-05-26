// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "BaseGameplayAbility.h"
#include "HeroGameplayAbility.generated.h"

class UHeroCombatComponent;
class ABaseHeroCharacter;
class AHeroPlayerController;

/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API UHeroGameplayAbility : public UBaseGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	ABaseHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	AHeroPlayerController* GetHeroPlayerControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

private:
	TWeakObjectPtr<ABaseHeroCharacter> CachedHeroCharacter;
	TWeakObjectPtr<AHeroPlayerController> CachedHeroPlayerController;
};
