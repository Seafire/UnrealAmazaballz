// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_PitObstacle.h"

void AC_PitObstacle::ObstacleResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	mesh_ = actor->FindComponentByClass<UStaticMeshComponent>();
	bool is_player = actor->ActorHasTag(player_tag_);

	// If this actor is a player character.
	if (is_player)
	{
		// If the mesh exists.
		if (mesh_)
		{
			entered_ = true;
			AC_Player* player = Cast<AC_Player>(actor);
			interacting_players_.push_back(player);

			if (destroyed_after_use_)
				Super::Destroy();
		}
	}
}

void AC_PitObstacle::ObstacleLeft(AActor* actor)
{
	bool is_player = actor->ActorHasTag(player_tag_);

	if (is_player)
	{
		AC_Player* player = Cast<AC_Player>(actor);

		// We could have something extra like a particle effect or something?
		if (!interacting_players_.empty())
		{
			for (size_t i = 0; i < interacting_players_.size(); i++)
			{
				// If this player should be removed from the obstacle colliding player vector.
				if (interacting_players_[i]->GetIndex() == player->GetIndex())
				{
					interacting_players_.erase(interacting_players_.begin() + i);
				}
			}
		}
	}
	entered_ = false;
}

void AC_PitObstacle::Tick(float DeltaTime)
{
	//if (entered_)
	//{
	//	mesh_->SetPhysicsLinearVelocity(mesh_->GetPhysicsLinearVelocity() * speed_multiplier_);
	//}
	if (!interacting_players_.empty())
	{
		for (size_t i = 0; i < interacting_players_.size(); i++)
		{
			UStaticMeshComponent* temp_mesh = interacting_players_[i]->FindComponentByClass<UStaticMeshComponent>();
			temp_mesh->SetPhysicsLinearVelocity(temp_mesh->GetPhysicsLinearVelocity() * speed_multiplier_);
		}
	}
}