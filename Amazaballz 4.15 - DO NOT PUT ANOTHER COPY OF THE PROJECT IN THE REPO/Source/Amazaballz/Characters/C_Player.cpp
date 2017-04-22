// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_Player.h"

/*
 * Sets the default values.
 */
AC_Player::AC_Player() :
	is_jumping_(false),
	should_respawn_(false),
	has_infinite_lives_(false),
	can_be_attacked_(true)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spawn_position_.Set(-1000.0f, -140.0f, 1000.0f);
}

/*
 * Called when the game starts or when spawned.
 */
void AC_Player::BeginPlay()
{
	Super::BeginPlay();
	mesh_ = FindComponentByClass<UStaticMeshComponent>();
}

/*
 * Called every frame.
 * @param DeltaTime the time passed since the last frame update.
 */
void AC_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/*
 * Called to bind functionality to input.
 * @param PlayerInputComponent the input component to bind player input to.
 */
void AC_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

/*
 * Used to move the player around.
 * @param axis_value the amount of input applied.
 * @param is_right whether movement is applying to the x axis or z axis.
 */
void AC_Player::Movement(float axis_value, bool is_right)
{
	if (is_simulating_physics())
	{
		FVector force = FVector::ZeroVector;

		if (is_right)
		{
			force.Set(0.0f, roll_torque_ * axis_value * GetWorld()->DeltaTimeSeconds, 0.0f);
		}
		else
		{ 
			force.Set(roll_torque_ * axis_value * GetWorld()->DeltaTimeSeconds, 0.0f, 0.0f);
		}

		mesh_->GetBodyInstance()->AddForce(force);
	}
}

/*
 * Used to make the player jump up.
 */
void AC_Player::Jump()
{
	if (is_simulating_physics())
	{
		if (!is_jumping_)
		{
			FVector impulse(0.0f, 0.0f, jump_impulse);
			mesh_->GetBodyInstance()->AddImpulse(impulse, false);
			is_jumping_ = true;
		}
	}
}

/*
 * Used to respawn the player in their respawn position.
 */
void AC_Player::Respawn()
{
	// If this player should be able to just constantly respawn back into the game.
	if (has_infinite_lives_)
	{
		// Teleport the player to the spawn position.
		mesh_->GetBodyInstance()->SetInstanceSimulatePhysics(true);
		mesh_->SetRelativeLocation(spawn_position_);
		should_respawn_ = false;
	}
	// Otherwise, the player has a limited amount of lives.
	else
	{
		if (should_respawn_)
		{
			if (mesh_)
			{
				// If the player still has lives, respawn them.
				if ((lives_ + 1) > 0)
				{
					// Teleport the player to the spawn position.
					mesh_->GetBodyInstance()->SetInstanceSimulatePhysics(true);
					mesh_->SetRelativeLocation(spawn_position_);
					should_respawn_ = false;
				}
				// Otherwise, the player has no lives left.
				else
					Super::Destroy();
			}
		}
	}
}

/*
 * Sets the jumping flag for the player.
 * @param value if the player is jumping or not.
 */
void AC_Player::SetIsJumping(const bool value)
{
	is_jumping_ = value;
}

/*
 * Sets the player index.
 * @param value the index value for this player.
 */
void AC_Player::SetIndex(const int value)
{
	index_ = value;
}

/*
 * Sets the lives that the player has.
 * @param value the number of lives to set for this player.
 */
void AC_Player::SetLives(const int value)
{
	lives_ = value;
}

/*
 * Sets what the current spawn position is.
 * @param value the new spawn position for this player.
 */
void AC_Player::SetSpawnPosition(const FVector value)
{
	spawn_position_ = value;
}

/*
 * Sets the current mortality status of the player.
 * @param value if this player should have infinite lives.
 */
void AC_Player::SetInfiniteLives(const bool value)
{
	has_infinite_lives_ = value;
}

/*
 * Gets the current player index.
 * @return int the index for this player.
 */
int& AC_Player::GetIndex()
{
	return index_;
}

/*
 * Gets the amount of lives this player has.
 * @return int the amount of lives for this player.
 */
int& AC_Player::GetLives()
{
	return lives_;
}

/*
 * Gets the current spawn position of the player.
 * @return FVector the current spawn position.
 */
FVector& AC_Player::GetSpawnPosition()
{
	return spawn_position_;
}

/*
 * Gets the current immortality status of the player.
 * @return bool if this player has infinite lives.
 */
bool& AC_Player::HasInfiniteLives()
{
	return has_infinite_lives_;
}