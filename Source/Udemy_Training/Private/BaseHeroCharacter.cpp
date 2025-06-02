// Copyright by MF


#include "BaseHeroCharacter.h"
#include "BaseAbilitySystemComponent.h"
#include "BaseGameTags.h"
#include "BaseHeroEnhancedInputComponent.h"
#include "DataAsset_StartUpDataBase.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAsset/DataAsset_InputConfig.h"
#include "Combat/HeroCombatComponent.h"


ABaseHeroCharacter::ABaseHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	// Configure character movement
	HeroMovementComponent = GetCharacterMovement();
	HeroMovementComponent->bOrientRotationToMovement = true;
	HeroMovementComponent->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	HeroMovementComponent->JumpZVelocity = 600.f;
	HeroMovementComponent->MaxWalkSpeed = 600.f;
	HeroMovementComponent->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom...
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetOffset = FVector(5.0f, 5.0f, 0.0f);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->SocketOffset = FVector(0.0f, 55.0f, 0.0f);
	SpringArm->bUsePawnControlRotation = true;

	// Create a camera...
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	// Create Hero Combat Component
	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));
	
}

void ABaseHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

#pragma region test
	// if (WarriorAbilitySystemComponent && WarriorAttributeSet)
	// {
	// 	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Orange, FString::Printf(TEXT("WarriorAbilitySystemComponent is valid! OwnerActor: %s, AvatarActor: %s"), *GetNameSafe(WarriorAbilitySystemComponent->GetOwnerActor()), *GetNameSafe(WarriorAbilitySystemComponent->GetAvatarActor())));
	// 	UE_LOG(LogTemp, Warning, TEXT("WarriorAbilitySystemComponent is valid! OwnerActor: %s, AvatarActor: %s"), *GetNameSafe(WarriorAbilitySystemComponent->GetOwnerActor()), *GetNameSafe(WarriorAbilitySystemComponent->GetAvatarActor()));
	// 	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Orange, FString::Printf(TEXT("WarriorAttributeSet is valid! OwnerActor: %s, AvatarActor: %s"), *GetNameSafe(WarriorAbilitySystemComponent->GetOwnerActor()), *GetNameSafe(WarriorAbilitySystemComponent->GetAvatarActor())));
	// 	UE_LOG(LogTemp, Warning, TEXT("WarriorAttributeSet is valid! OwnerActor: %s, AvatarActor: %s"), *GetNameSafe(WarriorAbilitySystemComponent->GetOwnerActor()), *GetNameSafe(WarriorAbilitySystemComponent->GetAvatarActor()));
	// 	Debug::Print(FString::Printf(TEXT("WarriorAbilitySystemComponent and warriorAttributeSet are valid!")));
	// }
#pragma endregion
	
	// Give start up data to ability system component, then give startup ability to the warrior ability system component
	if (! CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(CharacterAbilitySystemComponent);
		}
	}
}

void ABaseHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	checkf(InputConfigDataAsset, TEXT("InputConfigDataAsset is nullptr"));

	//Binding mapping context to local player
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
	{
		Subsystem->AddMappingContext(InputConfigDataAsset->DefaultWarriorMappingContext, 0);
	}

	// Binding input actions to customized base hero input component
	UBaseHeroEnhancedInputComponent* BaseHeroEnhancedInputComponent = Cast<UBaseHeroEnhancedInputComponent>(PlayerInputComponent);
	
	BaseHeroEnhancedInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ABaseHeroCharacter::Input_Move);
	BaseHeroEnhancedInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ABaseHeroCharacter::Input_Look);
	BaseHeroEnhancedInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Jump, ETriggerEvent::Started, this, &ACharacter::Jump);
	BaseHeroEnhancedInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Jump, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

	BaseHeroEnhancedInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ABaseHeroCharacter::Input_AbilityInputReleased);

}

void ABaseHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseHeroCharacter::Input_Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	if (Controller != nullptr)
	{
		const FRotator MovementRotation(0, Controller->GetControlRotation().Yaw, 0);
		if (MovementVector.Y != 0.0f)
		{
			const FVector ForwardDirection = FRotationMatrix(MovementRotation).GetUnitAxis(EAxis::X);
			AddMovementInput(ForwardDirection, MovementVector.Y);
		}

		if (MovementVector.X != 0.0f)
		{
			const FVector RightDirection = FRotationMatrix(MovementRotation).GetUnitAxis(EAxis::Y);
			AddMovementInput(RightDirection, MovementVector.X);
		}
		
	}
}

void ABaseHeroCharacter::Input_Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	
	if (LookAxisVector.X != 0.f)
	{
		AddControllerYawInput(LookAxisVector.X);
	}

	if (LookAxisVector.Y != 0.f)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ABaseHeroCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	CharacterAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void ABaseHeroCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	CharacterAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}
