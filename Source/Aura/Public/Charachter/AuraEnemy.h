// Coppyright Croop

#pragma once

#include "CoreMinimal.h"
#include "Charachter/Aura_BaseCharacter.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAura_BaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()

	public:
	AAuraEnemy();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted;
};
