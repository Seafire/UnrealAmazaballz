// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "C_SpeedsterPickup.h"

void AC_SpeedsterPickup::NormalSpeed()
{
	picked_up_ = false;

	if (destroyed_after_use_)
		PickupDestroy();
}

void AC_SpeedsterPickup::PickupResponse(AActor* actor)
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
			// We should check to see if the pickup affects just the player, all players, the enemy team, or just the ally team.
			if (player_controller_)
			{
				if (!picked_up_)
				{
					if (pickup_mesh_ && destroyed_after_use_)
						pickup_mesh_->SetVisibility(false);
			
					picked_up_ = true;

					if(!(speedster_factor_ < 1.0f))
						mesh_->SetPhysicsLinearVelocity(mesh_->GetPhysicsLinearVelocity() * speedster_factor_);

					// Enable player input after a set time.
					GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_SpeedsterPickup::NormalSpeed, speedster_timer_, false);
				}
			}
		}
	}
}

void AC_SpeedsterPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}

void AC_SpeedsterPickup::Tick(float DeltaTime)
{
	if (picked_up_)
	{
		// This will affect the player's speed.
		if (speedster_factor_ < 1.0f)
			mesh_->SetPhysicsLinearVelocity(mesh_->GetPhysicsLinearVelocity() * speedster_factor_);
	}
}