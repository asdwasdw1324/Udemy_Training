// Copyright by MF


#include "BaseAttributeSet.h"

UBaseAttributeSet::UBaseAttributeSet()
{
	InitCurrentHealth(100.f);
	InitMaxHealth(100.f);
	InitCurrentRange(100.f);
	InitMaxRange(100.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}
