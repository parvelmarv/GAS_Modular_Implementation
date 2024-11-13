// Coppyright Croop


#include "Charachter/AuraCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHud.h"

AAuraCharacter::AAuraCharacter()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0, 400.f, 0);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	//Server ability actor info for the server
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	//Client ability actor info for the server
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();

	if (AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHud* AuraHUD = Cast<AAuraHud>(AuraPlayerController->GetHUD()))
		{
			AuraHUD->InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}
 