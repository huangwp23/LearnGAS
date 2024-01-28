// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Abilities/GameplayAbility.h"
#include "GASCharacter.generated.h"


class UAttributeSetBase;

UCLASS(config=Game)
class AGASCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

public:
	AGASCharacter();
	

protected:

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="CharacterBase")
	UAbilitySystemComponent* AbilitySystem;

	UFUNCTION(BlueprintCallable, Category = "Ability System")
	void GiveAbility(TSubclassOf<UGameplayAbility> Ability);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Abilities")
	UAttributeSetBase* AttributeSet;
};

