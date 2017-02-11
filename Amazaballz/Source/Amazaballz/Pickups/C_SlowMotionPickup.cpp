// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "C_SlowMotionPickup.h"

void AC_SlowMotionPickup::NormalSpeed()
{
	picked_up_ = false;

	if (destroyed_after_use_)
		PickupDestroy();
}

void AC_SlowMotionPickup::PickupResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);
	UStaticMeshComponent* pickup_mesh_ = FindComponentByClass<UStaticMeshComponent>();
	mesh_ = actor->FindComponentByClass<UStaticMeshComponent>();
	player_controller_ = static_cast<APlayerController*>(actor);

	// If this actor is a player character.
	if (is_player)
	{
		// If the mesh exists.
		if (mesh_)
		{
			// We would need to loop through all of the other players.
			// And make them slow motion.
			if (player_controller_)
			{
				if (!picked_up_)
				{
					if (pickup_mesh_ && destroyed_after_use_)
						pickup_mesh_->SetVisibility(false);

					picked_up_ = true;

					// Enable player input after a set time.
					GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_SlowMotionPickup::NormalSpeed, slow_motion_timer_, false);
				}
			}
		}
	}
}

void AC_SlowMotionPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}

void AC_SlowMotionPickup::Tick(float DeltaTime)
{
	if (picked_up_)
	{
		// This will slow the player down.
		mesh_->SetPhysicsLinearVelocity(mesh_->GetPhysicsLinearVelocity() * slow_motion_factor_);
		mesh_->SetPhysicsAngularVelocity(mesh_->GetPhysicsAngularVelocity() * slow_motion_factor_);
	}
}