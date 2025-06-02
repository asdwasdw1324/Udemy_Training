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
	//Get Hero character, Hero player controller and Hero combat component class in the hero game ability class.
	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	ABaseHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	AHeroPlayerController* GetHeroPlayerControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "Hero|Ability")
	UHeroCombatComponent* GetHeroCombatComponentFromActorInfo();

	UFUNCTION(BlueprintCallable, Category = "Debug")
	void DebugPrintInputContexts(AHeroPlayerController* PC);

private:
	//Use weak points to cache hero character, hero player controller classed in the hero game ability class.
	TWeakObjectPtr<ABaseHeroCharacter> CachedHeroCharacter;
	TWeakObjectPtr<AHeroPlayerController> CachedHeroPlayerController;
};
