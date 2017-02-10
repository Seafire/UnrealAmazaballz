// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "C_SpeedBoostPickup.h"

void AC_SpeedBoostPickup::PickupResponse(ACharacter* character)
{
	//// Access to the player that has collided with this pickup.
	//player_ = new ACharacter();
	//player_ = UGameplayStatics::GetPlayerCharacter(GetWorld(), player_index);

	// Increase the speed of the player.
	//player_->GetCharacterMovement()->Velocity *= speed_;
	character->GetCharacterMovement()->Velocity *= speed_multiplier_;
}

void AC_SpeedBoostPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}