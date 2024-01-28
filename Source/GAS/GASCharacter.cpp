// Copyright Epic Games, Inc. All Rights Reserved.

#include "GASCharacter.h"
#include "GASCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystemComponent.h"
#include "AttributeSetBase.h"
#include "Components/SphereComponent.h"


//////////////////////////////////////////////////////////////////////////
// AGASCharacter

UAbilitySystemComponent* AGASCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}

AGASCharacter::AGASCharacter()
{
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystem");
	AttributeSet = CreateDefaultSubobject<UAttributeSetBase>("Attribute Set");
}

void AGASCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
}

void AGASCharacter::GiveAbility(TSubclassOf<UGameplayAbility> Ability)
{
	if (AbilitySystem)
	{
		if (HasAuthority() && Ability)
		{
			AbilitySystem->GiveAbility(FGameplayAbilitySpec(Ability, 1));
		}
		AbilitySystem->InitAbilityActorInfo(this, this);
	}
}



