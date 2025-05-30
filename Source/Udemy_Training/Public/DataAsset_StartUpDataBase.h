// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UBaseGameplayAbility;
class UBaseAbilitySystemComponent;

//Set up the base class for all data assets that will be used to give abilities to the ability system component.
//This class is used to give abilities to the ability system component when the character is possessed.
//Encapsulate the logic of giving abilities to the ability system component in a single class.
//The final called function is GiveAbility function in the UAbilitySystemComponent class.
//GiveAbility is not mean activate the ability, it only means give the ability to the ability system component.

/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
	
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "StartUpData")
	TArray<TSubclassOf<UBaseGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "StartUpData")
	TArray<TSubclassOf<UBaseGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UBaseGameplayAbility>>& InAbilitiesToGive, UBaseAbilitySystemComponent* InASCToGive, int32 ApplyLevel = 1);
};
