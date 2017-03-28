// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_InvisibilityPickup.h"

/*
 * Used to make the player visible again.
 */
void AC_InvisibilityPickup::Visibility()
{
	picked_up_ = false;

	if (destroyed_after_use_)
		PickupDestroy();
}

/*
 * Provides a standard response for colliding with this pickup.
 * @param actor the actor that is colliding with this game object.
 */
void AC_InvisibilityPickup::PickupResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);
	UStaticMeshComponent* pickup_mesh_ = FindComponentByClass<UStaticMeshComponent>();

	// If this actor is a player character.
	if (is_player)
	{
		//AC_Player* player = Cast<AC_Player>(actor);
		AC_Character* player = Cast<AC_Character>(actor);

		if (!picked_up_ && player->CanUsePickups())
		{
			//mesh_->SetVisibility(false);
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

/*
 * Defines what happens when we destroy this item.
 */
void AC_InvisibilityPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}