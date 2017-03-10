// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_SpeedsterPickup.h"

/*
 * Used to bring the player back to normal speed.
 */
void AC_SpeedsterPickup::NormalSpeed()
{
	picked_up_ = false;

	if (destroyed_after_use_)
		PickupDestroy();
}

/*
 * Provides a standard response for colliding with this pickup.
 * @param actor the actor that is colliding with this game object.
 */
void AC_SpeedsterPickup::PickupResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);
	UStaticMeshComponent* pickup_mesh_ = FindComponentByClass<UStaticMeshComponent>();
	mesh_ = actor->FindComponentByClass<UStaticMeshComponent>();
	player_controller_ = static_cast<APlayerController*>(actor);

	// If this actor is a player character.
	if (is_player)
	{
		AC_Player* player = Cast<AC_Player>(actor);

		// If the mesh exists.
		if (mesh_)
		{
			if (!picked_up_ && player->get_can_use_pickups())
			{			
				picked_up_ = true;

				if(!(speedster_factor_ < 1.0f))
					mesh_->SetPhysicsLinearVelocity(mesh_->GetPhysicsLinearVelocity() * speedster_factor_);

				// Enable player input after a set time.
				GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_SpeedsterPickup::NormalSpeed, speedster_timer_, false);

				// This should hopefully fix the multiple collisions messing up the freeze pickup timer response.
				// Need to test this out at Conor's.
				if (pickup_mesh_ && destroyed_after_use_)
				{
					pickup_mesh_->SetVisibility(false);
					pickup_mesh_->DestroyComponent();
				}
			}
		}
	}
}

/*
 * Defines what happens when we destroy this item.
 */
void AC_SpeedsterPickup::PickupDestroy()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}

/*
 * Called every frame.
 * @param DeltaTime the time passed since the last frame update.
 */
void AC_SpeedsterPickup::Tick(float DeltaTime)
{
	if (picked_up_)
	{
		// This will affect the player's speed.
		if (speedster_factor_ < 1.0f)
			mesh_->SetPhysicsLinearVelocity(mesh_->GetPhysicsLinearVelocity() * speedster_factor_);
	}
}