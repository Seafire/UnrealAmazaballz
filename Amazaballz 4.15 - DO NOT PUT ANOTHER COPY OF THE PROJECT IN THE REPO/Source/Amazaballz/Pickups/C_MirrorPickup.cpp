// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_MirrorPickup.h"

/*
 * Used to remove the mirror status from players.
 */
void AC_MirrorPickup::RemoveMirror()
{
	picked_up_ = false;

	// Stop mirroring logic here...
	//player->set_can_be_attacked(true);
	interacting_player_->SetCanBeAttacked(true);

	if (destroyed_after_use_)
		PickupDestroy();
}

/*
 * Provides a standard response for colliding with this pickup.
 * @param actor the actor that is colliding with this game object.
 */
void AC_MirrorPickup::PickupResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);
	UStaticMeshComponent* pickup_mesh_ = FindComponentByClass<UStaticMeshComponent>();

	// If this actor is a player character.
	if (is_player)
	{
		//AC_Player* player = Cast<AC_Player>(actor);
		interacting_player_ = Cast<AC_Character>(actor);

		if (!picked_up_ && interacting_player_->CanUsePickups())
		{
			// Mirror logic here.
			// The player should no longer be able to be attacked from other players.
			interacting_player_->SetCanBeAttacked(false);
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

/*
 * Defines what happens when we destroy this item.
 */
void AC_MirrorPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}

void AC_MirrorPickup::ApplyPickupEffect()
{}

void AC_MirrorPickup::UndoPickupEffect()
{}