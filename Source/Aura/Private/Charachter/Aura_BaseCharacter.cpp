// Coppyright Croop


#include "Charachter/Aura_BaseCharacter.h"

#include "Camera/CameraComponent.h"

// Sets default values
AAura_BaseCharacter::AAura_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WaeponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AAura_BaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AAura_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
