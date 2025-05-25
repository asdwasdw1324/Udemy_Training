// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "Animation/WarriorCharacterAnimInstance.h"
#include "WarriorHeroAnimInstance.generated.h"

class ABaseHeroCharacter;

/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API UWarriorHeroAnimInstance : public UWarriorCharacterAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|References")
	ABaseHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold = 5.0f;

	float IdleElapsedTime;
	
};
