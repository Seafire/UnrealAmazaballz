// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "C_FreezePickup.h"

void AC_FreezePickup::UnFreeze()
{
	picked_up_ = false;

	// If the body is static.
	// Make the body dynamic.
	if (!mesh_->GetBodyInstance()->IsInstanceSimulatingPhysics())
		mesh_->GetBodyInstance()->SetInstanceSimulatePhysics(true);

	if (destroyed_after_use_)
		PickupDestroy();
}

void AC_FreezePickup::PickupResponse(AActor* actor)
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
			// Checking to see if they are not equal to this player.
			// And then disable their input, and UnFreeze them after a timer.
			if (player_controller_)
			{		
				if (!picked_up_)
				{
					// Reset the speed of the player.
					mesh_->SetPhysicsLinearVelocity(FVector::ZeroVector);

					if(pickup_mesh_)
						pickup_mesh_->SetVisibility(false);

					// Use this for invisibility.
					//mesh_->SetVisibility(false);

					picked_up_ = true;

					// Enable player input after a set time.
					GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_FreezePickup::UnFreeze, freeze_timer_, false);
				}
			}
		}
	}
}

void AC_FreezePickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}

void AC_FreezePickup::Tick(float DeltaTime)
{
	if (picked_up_)
	{
		// This only slows the player down.
		// Use this for slow motion pickup.
		//mesh_->SetPhysicsLinearVelocity(FVector::ZeroVector);
		//mesh_->SetPhysicsAngularVelocity(FVector::ZeroVector);

		// If the body is dynamic.
		// Make the body static.
		if(mesh_->GetBodyInstance()->IsInstanceSimulatingPhysics())
			mesh_->GetBodyInstance()->SetInstanceSimulatePhysics(false);
	}
}