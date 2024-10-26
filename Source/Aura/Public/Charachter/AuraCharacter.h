// Coppyright Croop

#pragma once

#include "CoreMinimal.h"
#include "Charachter/Aura_BaseCharacter.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAura_BaseCharacter
{
	GENERATED_BODY()
public:
	AAuraCharacter();

private:
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UCameraComponent* Camera;
};
