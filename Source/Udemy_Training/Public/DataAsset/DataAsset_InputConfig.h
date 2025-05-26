// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "DataAsset_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

/**
 * 
 */

USTRUCT(BlueprintType)
struct FWarriorInputConfig
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input|Tag")
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input|Action")
	TObjectPtr<UInputAction> InputAction;

	bool IsValid() const
	{
		return InputTag.IsValid() && InputAction;
	}
	
};

UCLASS()
class UDEMY_TRAINING_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input|MappingContext")
	UInputMappingContext* DefaultWarriorMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (TitleProperty = "InputAction"))
	TArray<FWarriorInputConfig> NativeInputActions;

	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InputTag, bool bLogNotFound = true) const;


	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (TitleProperty = "InputAction"))
	TArray<FWarriorInputConfig> AbilityInputActions;
};
