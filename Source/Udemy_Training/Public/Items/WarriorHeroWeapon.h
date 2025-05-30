// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "WarriorBaseWeapon.h"
#include "WarriorStructTypes.h"
#include "WarriorHeroWeapon.generated.h"

/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API AWarriorHeroWeapon : public AWarriorBaseWeapon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, blueprintReadOnly, Category = "WeaponData")
	FWarriorHeroWeaponData HeroWeaponData;
};
