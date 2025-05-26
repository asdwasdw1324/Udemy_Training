// Copyright by MF


#include "DataAsset/DataAsset_InputConfig.h"
#include "InputAction.h"

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

