// Copyright by MF


#include "DataAsset/DataAsset_InputConfig.h"
#include "C:\Program Files\Epic Games\UE_5.5\Engine\Plugins\EnhancedInput\Source\EnhancedInput\Public\InputAction.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{

	for (const auto& Action : NativeInputActions)
	{
		if (Action.IsValid() && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}
	
	return nullptr;
}

UInputAction* UDataAsset_InputConfig::FindAbilityInputActionByTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
	for (const auto& Action : AbilityInputActions)
	{
		if (Action.IsValid() && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	return nullptr;
}
