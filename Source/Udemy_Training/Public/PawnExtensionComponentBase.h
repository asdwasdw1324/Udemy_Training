// Copyright by MF

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionComponentBase.generated.h"

//The shared pawn extension component base class.
//Provides access to owning pawn and controller.
//Any other components that need access to the owning pawn or controller should derive from this class
//Not only for the combat system, but also for the movement system, the animation system, etc.

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDEMY_TRAINING_API UPawnExtensionComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	//Template function to get the owning pawn.
	template <class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "T must be derived from APawn");
		return CastChecked<T>(GetOwner());
	}

	//GetOwningPawn function overload for APawn.
	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}

	//Template function to get the owning controller.
	template <class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "T must be derived from AController");
		return CastChecked<T>(GetOwningPawn()->GetController());
	}
	
};
