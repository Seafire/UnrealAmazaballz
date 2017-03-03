// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_CrystalSkullPickup.h"

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

void AC_CrystalSkullPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}