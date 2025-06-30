// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "WarriorEnumTypes.h"
#include "Abilities/GameplayAbility.h"
#include "BaseGameplayAbility.generated.h"

class UPawnCombatComponent;
class UBaseAbilitySystemComponent;

UENUM()
enum class EWarriorAbilityActivationPolicy : uint8
{
	OnTriggered UMETA(DisplayName = "On Triggered"),
	OnGiven UMETA(DisplayName = "On Given"),
};

/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API UBaseGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:

	//Override 2 functions to trigger when give ability and end ability.
	//Active and clear specific ability.
	//~ Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ Begin UGameplayAbility Interface.
	
	
	UPROPERTY(EditDefaultsOnly, Category = "WarriorAbility")
	EWarriorAbilityActivationPolicy AbilityActivationPolicy = EWarriorAbilityActivationPolicy::OnTriggered;

	//Get PawnCombatComponent class in the base game ability class. 
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	//Get BaseAbilitySystemComponent class in the base game ability class.
	UFUNCTION(BlueprintPure, Category = "Warrior|Ability")
	UBaseAbilitySystemComponent* GetBaseAbilitySystemComponentFromActorInfo() const;

	FActiveGameplayEffectHandle NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle);

	UFUNCTION(BlueprintCallable, Category = "Warrior|Ability", meta = (DisplayName = "Apply Gameplay Effect Spec Handle to Target Actor", ExpandEnumAsExecs = "OutSuccessType"))
	FActiveGameplayEffectHandle BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle, EWarriorSuccessType& OutSuccessType);
};
