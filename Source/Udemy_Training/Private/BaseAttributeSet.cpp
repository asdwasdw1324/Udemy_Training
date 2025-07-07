// Copyright by MF


#include "BaseAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "DebugHelper.h"

UBaseAttributeSet::UBaseAttributeSet()
{
	InitCurrentHealth(100.f);
	InitMaxHealth(100.f);
	InitCurrentRage(100.f);
	InitMaxRage(100.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}

void UBaseAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);
	}

	if (Data.EvaluatedData.Attribute == GetCurrentRageAttribute())
	{
		const float NewCurrentRage = FMath::Clamp(GetCurrentRage(), 0.f, GetMaxRage());
		SetCurrentRage(NewCurrentRage);
	}

	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();
		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone, 0.f, GetMaxHealth());
		SetCurrentHealth(NewCurrentHealth);

		const FString DebugString = FString::Printf(TEXT("Guardian: OldHealth: %f, DamageDone: %f, NewHealth: %f"), OldHealth, DamageDone, NewCurrentHealth);
		Debug::Print(DebugString, FColor::Green);
		
		if (NewCurrentHealth == 0.f)
		{
			Debug::Print(TEXT("The pawn is dead!"), FColor::MakeRandomColor());
		}
	}
	
}
