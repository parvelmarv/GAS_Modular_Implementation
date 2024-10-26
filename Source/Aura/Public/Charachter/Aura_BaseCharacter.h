// Copyright Croop

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Aura_BaseCharacter.generated.h"

UCLASS(Abstract)
class AURA_API AAura_BaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAura_BaseCharacter();
	

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat") 
	TObjectPtr<USkeletalMeshComponent> Weapon;

};
