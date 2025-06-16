// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "Udemy_Training/BaseCharacter.h"
#include "BaseEnemyCharacter.generated.h"

class UEnemyCombatComponent;

/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API ABaseEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ABaseEnemyCharacter();
	
	FORCEINLINE UEnemyCombatComponent* GetEnemyCombatComponent() const { return EnemyCombatComponent; }

	//~ Begin IPawnCombatInterface Interface.
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface.

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "CombatComponents")
	TObjectPtr<UEnemyCombatComponent> EnemyCombatComponent;

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.

private:
	void InitialEnemyStartUpData();
};
