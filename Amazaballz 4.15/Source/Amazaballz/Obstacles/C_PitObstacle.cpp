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

			if (destroyed_after_use_)
				Super::Destroy();
		}
	}
}

void AC_PitObstacle::ObstacleLeft()
{
	// We could have something extra like a particle effect or something?
	
	entered_ = false;
}

void AC_PitObstacle::Tick(float DeltaTime)
{
	if (entered_)
	{
		mesh_->SetPhysicsLinearVelocity(mesh_->GetPhysicsLinearVelocity() * speed_multiplier_);
	}
}