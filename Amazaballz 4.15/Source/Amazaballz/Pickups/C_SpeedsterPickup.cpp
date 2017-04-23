// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_SpeedsterPickup.h"

void AC_SpeedsterPickup::BeginPlay()
{
	Super::BeginPlay();

	original_speed_ = 600.0f;
	original_acceleration_ = 2048.0f;
}

/*
 * Used to bring the player back to normal speed.
 */
void AC_SpeedsterPickup::NormalSpeed()
{
	picked_up_ = false;

	interacting_player_->GetCharacterMovement()->MaxWalkSpeed = original_speed_;
	interacting_player_->GetCharacterMovement()->MaxAcceleration = original_acceleration_;

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
	UStaticMeshComponent* pickup_mesh = FindComponentByClass<UStaticMeshComponent>();

	// If this actor is a player character.
	if (is_player)
	{
		interacting_player_ = Cast<AC_Character>(actor);

		if (!picked_up_ && interacting_player_->CanUsePickups())
		{			
			picked_up_ = true;

			interacting_player_->GetCharacterMovement()->MaxWalkSpeed *= speedster_factor_;
			interacting_player_->GetCharacterMovement()->MaxAcceleration *= speedster_factor_;
			
			// Enable player input after a set time.
			GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_SpeedsterPickup::NormalSpeed, speedster_timer_, false);

			// This should hopefully fix the multiple collisions messing up the freeze pickup timer response.
			// Need to test this out at Conor's.
			if (pickup_mesh && destroyed_after_use_)
			{
				pickup_mesh->SetVisibility(false);
				pickup_mesh->DestroyComponent();
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

void AC_SpeedsterPickup::ApplyPickupEffect()
{}

void AC_SpeedsterPickup::UndoPickupEffect()
{}