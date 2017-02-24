// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_HoleObstacle.h"

void AC_HoleObstacle::Respawn(UStaticMeshComponent* mesh)
{
	FVector spawn_position(-1000.0f, -140.0f, 1000.0f);

	// Teleport the player to the spawn position.
	if (mesh)
	{
		mesh->GetBodyInstance()->SetInstanceSimulatePhysics(true);
		mesh->SetRelativeLocation(spawn_position);
	}

	if (destroyed_after_use_)
		Super::Destroy();
}

void AC_HoleObstacle::ObstacleResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);
	UStaticMeshComponent* pickup_mesh_ = FindComponentByClass<UStaticMeshComponent>();
	//mesh_ = temp_actor->FindComponentByClass<UStaticMeshComponent>();
	player_controller_ = static_cast<APlayerController*>(actor);

	// If this actor is a player character.
	if (is_player)
	{
		// If the mesh exists.
		//if (mesh_)
		//{
			if (player_controller_)
			{
				AC_Player* player = Cast<AC_Player>(actor);
				interacting_players_.push_back(player);

				// Reset the speed of the player.
				//mesh_->SetPhysicsLinearVelocity(FVector::ZeroVector);

				//if (pickup_mesh_ && destroyed_after_use_)
				//	pickup_mesh_->SetVisibility(false);

				//if (mesh_->GetBodyInstance()->IsInstanceSimulatingPhysics())
				//	mesh_->GetBodyInstance()->SetInstanceSimulatePhysics(false);

				// Enable player input after a set time.
				//GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_HoleObstacle::Respawn, death_delay_, false);
				
			}
		//}
	}

	if (!interacting_players_.empty())
	{
		for (size_t i = 0; i < interacting_players_.size(); i++)
		{
			UStaticMeshComponent* mesh = interacting_players_[i]->FindComponentByClass<UStaticMeshComponent>();
			
			// Reset the speed of the player.
			mesh->SetPhysicsLinearVelocity(FVector::ZeroVector);
			
			if (pickup_mesh_ && destroyed_after_use_)
				pickup_mesh_->SetVisibility(false);

			if (mesh->GetBodyInstance()->IsInstanceSimulatingPhysics())
				mesh->GetBodyInstance()->SetInstanceSimulatePhysics(false);

			Respawn(mesh);
			// Enable player input after a set time.
			//timer_del_.BindUFunction(this, FName("Respawn"), mesh);
			//GetWorldTimerManager().SetTimer(unused_handle_, timer_del_, death_delay_, false);
		}
	}
}

void AC_HoleObstacle::ObstacleLeft(AActor* actor)
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	//Super::Destroy();

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

}