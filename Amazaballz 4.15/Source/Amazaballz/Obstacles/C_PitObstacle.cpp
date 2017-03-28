// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_PitObstacle.h"

/*
 * Provides a standard response for colliding with this obstacle.
 * @param actor the actor that is colliding with this game object.
 */
void AC_PitObstacle::ObstacleResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	//mesh_ = actor->FindComponentByClass<UStaticMeshComponent>();
	character_movement_ = actor->FindComponentByClass<UCharacterMovementComponent>();
	bool is_player = actor->ActorHasTag(player_tag_);

	// If this actor is a player character.
	if (is_player)
	{
		entered_ = true;
		AC_Character* player = Cast<AC_Character>(actor);
		interacting_players_.push_back(player);
		
		if (destroyed_after_use_)
			Super::Destroy();
	}
}

/*
 * Provides a standard response for exiting colliders with this obstacle.
 * @param actor the actor that is no longer colliding with this game object.
 */
void AC_PitObstacle::ObstacleLeft(AActor* actor)
{
	bool is_player = actor->ActorHasTag(player_tag_);

	if (is_player)
	{
		AC_Character* player = Cast<AC_Character>(actor);

		// We could have something extra like a particle effect or something?
		if (!interacting_players_.empty())
		{
			for (size_t i = 0; i < interacting_players_.size(); ++i)
			{
				// Temporary reference, so there are less calls to the pointer reference in the vector.
				AC_Character* character = interacting_players_[i];

				// If this player should be removed from the obstacle colliding player vector.
				if (character->GetIndex() == player->GetIndex())
				{
					character->SetSpeedToNormal();
					interacting_players_.erase(interacting_players_.begin() + i);
				}
			}
		}
	}
	entered_ = false;
}

/*
 * Called every frame.
 * @param DeltaTime the time passed since the last frame update.
 */
void AC_PitObstacle::Tick(float DeltaTime)
{
	if (!interacting_players_.empty())
	{
		for (size_t i = 0; i < interacting_players_.size(); i++)
		{
			AC_Character* character = interacting_players_[i];

			if (character->GetSpeed() != speed_multiplier_)
				character->SetSpeed(speed_multiplier_);
		}
	}
}