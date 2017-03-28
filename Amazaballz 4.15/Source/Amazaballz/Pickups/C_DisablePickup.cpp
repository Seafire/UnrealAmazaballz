// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_DisablePickup.h"

/*
 * Used when this pickup should restore the player's ability
 * to use pickups again.
 */
void AC_DisablePickup::EnablePickups()
{
	picked_up_ = false;

	// Enable other player pickups after use.
	//player->set_can_use_pickups(true);
	interacting_player_->SetCanUsePickups(true);

	if (destroyed_after_use_)
		PickupDestroy();
}

/*
 * Provides a standard response for colliding with this pickup.
 * @param actor the actor that is colliding with this game object.
 */
void AC_DisablePickup::PickupResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);
	UStaticMeshComponent* pickup_mesh_ = FindComponentByClass<UStaticMeshComponent>();
	
	// If this actor is a player character.
	if (is_player)
	{
		//AC_Player* player = Cast<AC_Player>(actor);
		//AC_Character* player = Cast<AC_Character>(actor);
		interacting_player_ = Cast<AC_Character>(actor);

		// We would need to loop through all of the other players.
		// Checking to see if they are not equal to this player.
		// And then disable their input, and UnFreeze them after a timer.
		if (!picked_up_ && interacting_player_->CanUsePickups())
		{
			// Disable other player pickup logic here
			// Need to loop through all of the players and use the below line.
			//player->set_can_use_pickups(false);
			interacting_player_->SetCanUsePickups(false);

			picked_up_ = true;

			// Enable player pickups after a set time.
			GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_DisablePickup::EnablePickups, disable_timer_, false);

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
void AC_DisablePickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}