// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_FreezePickup.h"

/*
 * Used to enable player movement again.
 */
void AC_FreezePickup::UnFreeze()
{
	picked_up_ = false;
	
	mesh_->GetBodyInstance()->SetInstanceSimulatePhysics(true);

	if (destroyed_after_use_)
		PickupDestroy();
}

/*
 * Provides a standard response for colliding with this pickup.
 * @param actor the actor that is colliding with this game object.
 */
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
		AC_Player* player = Cast<AC_Player>(actor);

		// If the mesh exists.
		if (mesh_)
		{				
			if (!picked_up_ && player->get_can_use_pickups())
			{
				// Reset the speed of the player.
				mesh_->SetPhysicsLinearVelocity(FVector::ZeroVector);

				if (mesh_->GetBodyInstance()->IsInstanceSimulatingPhysics())
					mesh_->GetBodyInstance()->SetInstanceSimulatePhysics(false);

				picked_up_ = true;

				// This also needs to set the collision of this pickup to be disabled.
				// So that the pickup is actually destroyed correctly.

				// Enable player input after a set time.
				GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_FreezePickup::UnFreeze, freeze_timer_, false);

				// This should hopefully fix the multiple collisions messing up the freeze pickup timer response.
				// Need to test this out at Conor's.
				if (pickup_mesh_ && destroyed_after_use_)
				{
					pickup_mesh_->SetVisibility(false);
					pickup_mesh_->DestroyComponent();
				}
			}
		}
	}
}

/*
 * Defines what happens when we destroy this item.
 */
void AC_FreezePickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}