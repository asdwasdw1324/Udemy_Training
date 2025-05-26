// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "Udemy_Training/BaseCharacter.h"
#include "GameplayTagContainer.h"
#include "BaseHeroCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputComponent;
class UCharacterMovementComponent;
class UDataAsset_InputConfig;
class UDataAsset_StartUpDataBase;
struct FInputActionValue;
class UHeroCombatComponent;


/**
 * 
 */
UCLASS()
class UDEMY_TRAINING_API ABaseHeroCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ABaseHeroCharacter();

protected:

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.
	
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;;
	
	virtual void BeginPlay() override;

private:
#pragma region Components
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(VisibleAnywhere, Category = "Camera", meta = (AllowPrivateAccess = "true"))	
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCharacterMovementComponent> HeroMovementComponent;

	UPROPERTY(VisibleAnywhere, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHeroCombatComponent> HeroCombatComponent;
#pragma endregion

	UPROPERTY(EditDefaultsOnly, Category = "CharacterData", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDataAsset_InputConfig> InputConfigDataAsset;

#pragma region Input
	void Input_Move(const FInputActionValue& Value);
	void Input_Look(const FInputActionValue& Value);

	void Input_AbilityInputPressed(FGameplayTag InInputTag);
	void Input_AbilityInputReleased(FGameplayTag InInputTag);
	
#pragma endregion

public:
	FORCEINLINE UHeroCombatComponent* GetHeroCombatComponent() const { return HeroCombatComponent; }
	
};
