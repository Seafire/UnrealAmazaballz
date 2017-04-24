// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_ProjectileObstacle.h"

void AC_ProjectileObstacle::FireProjectiles()
{
	if (projectiles_.Num() > 0)
	{
		for (size_t i = 0; i < projectiles_.Num(); ++i)
		{
			AActor* actor = projectiles_[i];
			AC_Projectile* projectile = Cast<AC_Projectile>(actor);

			// Fire a projectile! CLICK CLIKK BOOM.
			projectile->Init(GetOwner()->GetActorForwardVector(), 10.0f);
		}
	}

	if (destroyed_after_use_)
		Super::Destroy();
}

void AC_ProjectileObstacle::ObstacleResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);

	// If this actor is a player character.
	if (is_player)
	{
		AC_Character* player = Cast<AC_Character>(actor);
		UStaticMeshComponent* pickup_mesh = FindComponentByClass<UStaticMeshComponent>();

		//
		// Fire projectiles after a set time.
		//

		// This one will loop.
		//GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_ProjectileObstacle::FireProjectiles, projectile_delay_, true);
		
		// This one will be a one off shot.
		GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_ProjectileObstacle::FireProjectiles, projectile_delay_, false);
		
		// Disable any more players activating this obstacle.
		pickup_mesh->DestroyComponent();
	}
}

void AC_ProjectileObstacle::ObstacleLeft(AActor* actor)
{
	bool is_player = actor->ActorHasTag(player_tag_);

	if (is_player)
	{
		AC_Character* player = Cast<AC_Character>(actor);

		
	}
}