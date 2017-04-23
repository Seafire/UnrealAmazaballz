// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_OrbOfPowerPickup.h"

void AC_OrbOfPowerPickup::PickupResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);

	// If this actor is a player character.
	if (is_player)
	{
		AC_Character* player = Cast<AC_Character>(actor);
		UC_PowerComponent* power_component = player->FindComponentByClass<UC_PowerComponent>();

		if (power_component)
		{
			if(!power_component->IsAtMax())
				power_component->IncreasePower(amount_of_power_);

			if (destroyed_after_use_)
				PickupDestroy();
		}
	}
}

void AC_OrbOfPowerPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}

void AC_OrbOfPowerPickup::ApplyPickupEffect()
{}

void AC_OrbOfPowerPickup::UndoPickupEffect()
{}