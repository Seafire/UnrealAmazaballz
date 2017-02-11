// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "C_SpeedBoostPickup.h"

void AC_SpeedBoostPickup::PickupResponse(ACharacter* character)
{
	// Accessing the static mesh component of the character.
	UStaticMeshComponent* mesh = character->FindComponentByClass<UStaticMeshComponent>();

	// If the mesh exists.
	if (mesh)
	{
		// Access the linear velocity of the character and multiply it by the speed multiplier.
		FVector linear_velocity = mesh->GetPhysicsLinearVelocity();
		FVector new_velocity = linear_velocity * speed_multiplier_;

		// Increase the speed of the character.
		mesh->SetPhysicsLinearVelocity(new_velocity);
	}
}

void AC_SpeedBoostPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}