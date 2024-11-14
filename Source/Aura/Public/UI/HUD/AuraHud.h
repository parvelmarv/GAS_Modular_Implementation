// Coppyright Croop

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHud.generated.h"


class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class UAuraUserWidget;
/**
 * 
 */
UCLASS()
class AURA_API AAuraHud : public AHUD
{
	GENERATED_BODY()
public:

	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);

	UPROPERTY()
	TObjectPtr<UAuraUserWidget> OverlayWidget;

	void InitOverlay(APlayerController* PC, APlayerState* AP, UAbilitySystemComponent* ASC, UAttributeSet* AS);

protected:
	
	
private:

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
};
