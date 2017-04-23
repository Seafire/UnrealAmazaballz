// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_SpeedBoostPickup.h"

void AC_SpeedBoostPickup::BeginPlay()
{
	Super::BeginPlay();

	original_speed_ = 600.0f;
	original_acceleration_ = 2048.0f;
}

void AC_SpeedBoostPickup::NormalSpeed()
{
	interacting_player_->GetCharacterMovement()->MaxWalkSpeed = original_speed_;
	interacting_player_->GetCharacterMovement()->MaxAcceleration = original_acceleration_;

	if (destroyed_after_use_)
		PickupDestroy();
}

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
		interacting_player_ = Cast<AC_Character>(actor);
		interacting_player_->GetCharacterMovement()->MaxWalkSpeed *= speed_multiplier_;
		interacting_player_->GetCharacterMovement()->MaxAcceleration *= speed_multiplier_;

		// Make the player visibile after a set time.
		if (destroyed_after_use_)
			PickupDestroy();
		else
			GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_SpeedBoostPickup::NormalSpeed, 0.5f, false);
	}
}

/*
 * Defines what happens when we destroy this item.
 */
void AC_SpeedBoostPickup::PickupDestroy()
{
	interacting_player_->GetCharacterMovement()->MaxWalkSpeed = original_speed_;
	interacting_player_->GetCharacterMovement()->MaxAcceleration = original_acceleration_;

	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	Super::Destroy();
}

void AC_SpeedBoostPickup::ApplyPickupEffect()
{}

void AC_SpeedBoostPickup::UndoPickupEffect()
{}