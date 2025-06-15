// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "DataAsset_StartUpDataBase.h"
#include "DataAsset_StartUpDataEnemyBase.generated.h"

class UEnemyGameplayAbility;

/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API UDataAsset_StartUpDataEnemyBase : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<TSubclassOf<UEnemyGameplayAbility>> EnemyCombatAbilities;

public:
	virtual void GiveToAbilitySystemComponent(UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1) override;
};
