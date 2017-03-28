// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_HoleObstacle.h"

/*
 * Used when holes should respawn the player.
 */
void AC_HoleObstacle::Respawn()
{	
	if (!interacting_players_.empty())
	{
		for (size_t i = 0; i < interacting_players_.size(); ++i)
		{
			if (interacting_players_[i]->IsSpawning())
				interacting_players_[i]->Respawn();
		}
	}

	if (destroyed_after_use_)
		Super::Destroy();
}

/*
 * Provides a standard response for colliding with this obstacle.
 * @param actor the actor that is colliding with this game object.
 */
void AC_HoleObstacle::ObstacleResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);

	// If this actor is a player character.
	if (is_player)
	{
		AC_Character* player = Cast<AC_Character>(actor);
		player->SetSpawningStatus(true);

		if (!player->HasInfiniteLives())
			player->SetLives(player->GetLives() - 1);

		interacting_players_.push_back(player);
	}

	if (!interacting_players_.empty())
	{
		for (size_t i = 0; i < interacting_players_.size(); ++i)
		{
			Respawn();

			// NOTE NEED HELP IMPLEMENTING RESPAWN DELAY...
			//	// This timer doesn't seem to work...
			//	//GetWorldTimerManager().SetTimer(unused_handle_, timer_del_, death_delay_, false);
		}
	}
}

/*
 * Provides a standard response for exiting colliders with this obstacle.
 * @param actor the actor that is no longer colliding with this game object.
 */
void AC_HoleObstacle::ObstacleLeft(AActor* actor)
{
	bool is_player = actor->ActorHasTag(player_tag_);

	if (is_player)
	{
		AC_Character* player = Cast<AC_Character>(actor);

		if (!interacting_players_.empty())
		{
			for (size_t i = 0; i < interacting_players_.size(); i++)
			{
				AC_Character* currentPlayer = interacting_players_[i];

				if (currentPlayer->GetIndex() == player->GetIndex())
					interacting_players_.erase(interacting_players_.begin() + i);
			}
		}
	}
}