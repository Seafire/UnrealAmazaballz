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
		/*for (size_t i = 0; i < interacting_players_.size(); ++i)
		{
			if (interacting_players_[i]->get_is_spawning())
				interacting_players_[i]->Respawn();
		}*/
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
	//UStaticMeshComponent* pickup_mesh_ = FindComponentByClass<UStaticMeshComponent>();

	// If this actor is a player character.
	if (is_player)
	{
		/*AC_Player* player = Cast<AC_Player>(actor);
		player->set_is_spawning(true);

		if(!player->HasInfiniteLives())
			player->SetLives(player->GetLives() - 1);

		interacting_players_.push_back(player);*/
	}

	if (!interacting_players_.empty())
	{
		//for (size_t i = 0; i < interacting_players_.size(); i++)
		//{
		//	UStaticMeshComponent* mesh = interacting_players_[i]->FindComponentByClass<UStaticMeshComponent>();
		//	
		//	// Reset the speed of the player.
		//	mesh->SetPhysicsLinearVelocity(FVector::ZeroVector);
		//	
		//	if (pickup_mesh_ && destroyed_after_use_)
		//		pickup_mesh_->SetVisibility(false);

		//	if (mesh->GetBodyInstance()->IsInstanceSimulatingPhysics())
		//		mesh->GetBodyInstance()->SetInstanceSimulatePhysics(false);

		//	Respawn();

		//	// This timer doesn't seem to work...
		//	//GetWorldTimerManager().SetTimer(unused_handle_, timer_del_, death_delay_, false);
		//}
	}
}

/*
 * Provides a standard response for exiting colliders with this obstacle.
 * @param actor the actor that is no longer colliding with this game object.
 */
void AC_HoleObstacle::ObstacleLeft(AActor* actor)
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	//Super::Destroy();

	bool is_player = actor->ActorHasTag(player_tag_);

	if (is_player)
	{
		//AC_Player* player = Cast<AC_Player>(actor);

		//// We could have something extra like a particle effect or something?
		//if (!interacting_players_.empty())
		//{
		//	for (size_t i = 0; i < interacting_players_.size(); i++)
		//	{
		//		// If this player should be removed from the obstacle colliding player vector.
		//		if (interacting_players_[i]->GetIndex() == player->GetIndex())
		//		{
		//			interacting_players_.erase(interacting_players_.begin() + i);
		//		}
		//	}
		//}
	}

}