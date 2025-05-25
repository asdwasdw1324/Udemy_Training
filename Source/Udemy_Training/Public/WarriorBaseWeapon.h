// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WarriorBaseWeapon.generated.h"

class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class UDEMY_TRAINING_API AWarriorBaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWarriorBaseWeapon();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weapon")
	TObjectPtr<UStaticMeshComponent> WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Weapon")
	TObjectPtr<UBoxComponent> WeaponCollisionBox;

public:
	FORCEINLINE UBoxComponent* GetWeaponCollisionBox() const { return WeaponCollisionBox; }
};
