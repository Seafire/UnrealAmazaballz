// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_CrystalSkullPickup.h"

/*
 * Provides a standard response for colliding with this pickup.
 * @param actor the actor that is colliding with this game object.
 */
void AC_CrystalSkullPickup::PickupResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	UStaticMeshComponent* mesh = actor->FindComponentByClass<UStaticMeshComponent>();
	bool is_player = actor->ActorHasTag(player_tag_);
	
	// If this actor is a player character.
	if (is_player)
	{
		AC_Player* player = Cast<AC_Player>(actor);

		// If the mesh exists.
		if (mesh)
		{
			if (player->get_can_use_pickups())
			{
				// Crystal skull logic.
				if (!player->HasInfiniteLives())
					player->SetLives(player->GetLives() + 1);

				if (destroyed_after_use_)
					PickupDestroy();
			}
		}
	}
}

/*
 * Provides a standard response when the player has picked it up.
 */
void AC_CrystalSkullPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}