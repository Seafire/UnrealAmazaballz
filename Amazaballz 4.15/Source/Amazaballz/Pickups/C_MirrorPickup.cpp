// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_MirrorPickup.h"

void AC_MirrorPickup::RemoveMirror()
{
	picked_up_ = false;

	// Stop mirroring logic here...
	//player->set_can_be_attacked(true);

	if (destroyed_after_use_)
		PickupDestroy();
}

void AC_MirrorPickup::PickupResponse(AActor* actor)
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
				AC_Player* player = Cast<AC_Player>(actor);

				if (!picked_up_)
				{
					// Mirror logic here.
					// The player should no longer be able to be attacked from other players.
					player->set_can_be_attacked(false);
					picked_up_ = true;
					
					// Enable player input after a set time.
					GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_MirrorPickup::RemoveMirror, mirror_timer_, false);

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
}

void AC_MirrorPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}