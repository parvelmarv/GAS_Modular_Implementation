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

	/** Enemy Interface **/
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** End Enemy Interface **/

	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted;

	protected:
	virtual void BeginPlay() override;
};
