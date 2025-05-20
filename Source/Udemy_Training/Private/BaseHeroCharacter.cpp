// Copyright by MF


#include "BaseHeroCharacter.h"

#include "BaseGameTags.h"
#include "BaseHeroEnhancedInputComponent.h"
#include "DebugHelper.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputSubsystems.h"
#include "DataAsset/DataAsset_InputConfig.h"


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
	SpringArm->TargetOffset = FVector(0.0f, 0.0f, 0.0f);
	SpringArm->TargetArmLength = 300.0f;
	SpringArm->SocketOffset = FVector(0.0f, 55.0f, 0.0f);
	SpringArm->bUsePawnControlRotation = true;

	// Create a camera...
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	FollowCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

void ABaseHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("InputConfigDataAsset is nullptr"));

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
	{
		Subsystem->AddMappingContext(InputConfigDataAsset->DefaultWarriorMappingContext, 0);
	}

	UBaseHeroEnhancedInputComponent* HeroEnhancedInputComponent= CastChecked<UBaseHeroEnhancedInputComponent>(PlayerInputComponent);
	HeroEnhancedInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ABaseHeroCharacter::Input_Move);
	HeroEnhancedInputComponent->BindNativeInputAction(InputConfigDataAsset, WarriorGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ABaseHeroCharacter::Input_Look);
}

void ABaseHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("GameStart!"));
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
