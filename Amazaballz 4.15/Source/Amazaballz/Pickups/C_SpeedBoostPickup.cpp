// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_SpeedBoostPickup.h"

/*
 * Provides a standard response for colliding with this pickup.
 * @param actor the actor that is colliding with this game object.
 */
void AC_SpeedBoostPickup::PickupResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);

	// If this actor is a player character.
	if (is_player)
	{
		AC_Character* player = Cast<AC_Character>(actor);

		// Access the linear velocity of the character and multiply it by the speed multiplier.
		FVector linear_velocity = FVector::ZeroVector;
		FVector new_velocity = linear_velocity * speed_multiplier_;

		// Increase the speed of the character.
		//mesh->SetPhysicsLinearVelocity(new_velocity);

		if (destroyed_after_use_)
			PickupDestroy();
	}
}

/*
 * Defines what happens when we destroy this item.
 */
void AC_SpeedBoostPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}