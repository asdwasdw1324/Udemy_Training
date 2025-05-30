// Copyright by MF


#include "Animation/WarriorHeroLinkedAnimLayer.h"

#include "Animation/WarriorHeroAnimInstance.h"

UWarriorHeroAnimInstance* UWarriorHeroLinkedAnimLayer::GetWarriorHeroAnimInstance() const
{
	return Cast<UWarriorHeroAnimInstance>(GetOwningComponent()->GetAnimInstance());
}
