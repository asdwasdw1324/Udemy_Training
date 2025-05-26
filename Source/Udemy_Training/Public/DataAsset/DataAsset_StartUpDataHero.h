// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_StartUpDataBase.h"
#include "GameplayTagContainer.h"
#include "DataAsset_StartUpDataHero.generated.h"

class UHeroGameplayAbility;

USTRUCT(BlueprintType)
struct FWarriorHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UHeroGameplayAbility> AbilityToGrant;

	bool IsValid() const;
	
};

/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API UDataAsset_StartUpDataHero : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FWarriorHeroAbilitySet> HeroStartUpAbilitySets;

public:
	virtual void GiveToAbilitySystemComponent(UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;
};
