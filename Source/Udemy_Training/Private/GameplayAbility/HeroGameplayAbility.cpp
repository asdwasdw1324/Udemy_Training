// Copyright by MF


#include "GameplayAbility/HeroGameplayAbility.h"
#include "BaseHeroCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "HeroGameBase/HeroPlayerController.h"
#include "EnhancedPlayerInput.h"
#include "EnhancedInputComponent.h"

ABaseHeroCharacter* UHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedHeroCharacter.IsValid())
	{
		CachedHeroCharacter = Cast<ABaseHeroCharacter>(GetAvatarActorFromActorInfo());
	}

	return CachedHeroCharacter.IsValid() ? CachedHeroCharacter.Get() : nullptr;
}

AHeroPlayerController* UHeroGameplayAbility::GetHeroPlayerControllerFromActorInfo()
{
	if (!CachedHeroPlayerController.IsValid())
	{
		CachedHeroPlayerController = CastChecked<AHeroPlayerController>(CurrentActorInfo->PlayerController);
	}
	return CachedHeroPlayerController.IsValid() ? CachedHeroPlayerController.Get() : nullptr;
}

UHeroCombatComponent* UHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}

void UHeroGameplayAbility::DebugPrintInputContexts(AHeroPlayerController* PC)
{
    // 检查玩家控制器是否有效
    if (!PC)
    {
        UE_LOG(LogTemp, Error, TEXT("DebugPrintInputContexts: 玩家控制器（PC）为空，无法继续"));
        return;
    }

    // 获取本地玩家（LocalPlayer）
    if (ULocalPlayer* LocalPlayer = PC->GetLocalPlayer())
    {
        UE_LOG(LogTemp, Log, TEXT("DebugPrintInputContexts: 成功获取 LocalPlayer"));

        // 获取增强输入子系统
        if (UEnhancedInputLocalPlayerSubsystem* EnhancedSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer))
        {
            UE_LOG(LogTemp, Log, TEXT("DebugPrintInputContexts: 成功获取增强输入子系统（EnhancedSubsystem）"));

            // 获取当前应用的输入上下文列表
            
            
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("DebugPrintInputContexts: 无法从 LocalPlayer 获取增强输入子系统"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("DebugPrintInputContexts: 无法从玩家控制器（PC）获取 LocalPlayer"));
    }
}
