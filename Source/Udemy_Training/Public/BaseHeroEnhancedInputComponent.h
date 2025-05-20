// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAsset/DataAsset_InputConfig.h"
#include "BaseHeroEnhancedInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API UBaseHeroEnhancedInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallBackFunc>	
	inline void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallBackFunc Func)
	{
		checkf(InInputConfig, TEXT("InputConfig is nullptr"));
		if (UInputAction* FoundInputAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
		{	
			BindAction(FoundInputAction, TriggerEvent, ContextObject, Func);
		}
	}
};
