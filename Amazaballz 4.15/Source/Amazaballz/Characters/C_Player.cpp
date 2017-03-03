// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_Player.h"

/*
 * Sets the default values.
 */
AC_Player::AC_Player() :
	is_jumping_(false)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
 * Gets the current player index.
 * @return int the index for this player.
 */
int& AC_Player::GetIndex()
{
	return index_;
}