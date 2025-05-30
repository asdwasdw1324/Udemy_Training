// Copyright by MF


#include "DataAsset/DataAsset_InputConfig.h"
#include "InputAction.h"

UInputAction* UDataAsset_InputConfig::FindNativeInputActionByTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{

	for (const auto& InputAction : NativeInputActions)
	{
		if (InputAction.IsValid() && InputAction.InputTag == InputTag)
		{
			return InputAction.InputAction;
		}
	}
	
	return nullptr;
}

