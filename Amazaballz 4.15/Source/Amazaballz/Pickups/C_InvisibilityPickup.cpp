// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_InvisibilityPickup.h"

void AC_InvisibilityPickup::Visibility()
{
	picked_up_ = false;
	mesh_->SetVisibility(true);

	if (destroyed_after_use_)
		PickupDestroy();
}

void AC_InvisibilityPickup::PickupResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);
	UStaticMeshComponent* pickup_mesh_ = FindComponentByClass<UStaticMeshComponent>();
	mesh_ = actor->FindComponentByClass<UStaticMeshComponent>();

	// If this actor is a player character.
	if (is_player)
	{
		// If the mesh exists.
		if (mesh_)
		{
			if (!picked_up_)
			{
				mesh_->SetVisibility(false);
				picked_up_ = true;

				// Make the player visibile after a set time.
				GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_InvisibilityPickup::Visibility, invisibility_timer_, false);

				// This should hopefully fix the multiple collisions messing up the timer response.
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

void AC_InvisibilityPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}