// Copyright by MF


#include "BaseAttributeSet.h"

UBaseAttributeSet::UBaseAttributeSet()
{
	InitCurrentHealth(100.f);
	InitMaxHealth(100.f);
	InitCurrentRage(100.f);
	InitMaxRage(100.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}
