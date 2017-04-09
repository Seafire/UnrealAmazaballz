// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_Character.h"


// Sets default values
AC_Character::AC_Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Setting custom player properties.
	original_speed_ = speed_;
	current_target_ = nullptr;

	if (player_index_ != -1)
	{
		APlayerController* player_controller = Cast<APlayerController>(GetActorClass());
		UGameplayStatics::SetPlayerControllerID(player_controller, player_index_);
	}
}

//////////////////////////////////////////////////////////////////////////
// Input

void AC_Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AC_Character::Attack);
	PlayerInputComponent->BindAction("Attack", IE_Released, this, &AC_Character::StopAttack);
	PlayerInputComponent->BindAction("Defend", IE_Pressed, this, &AC_Character::Defend);
	PlayerInputComponent->BindAction("Defend", IE_Released, this, &AC_Character::StopDefend);

	PlayerInputComponent->BindAxis("MoveForward", this, &AC_Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AC_Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AC_Character::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AC_Character::LookUpAtRate);

	spawn_position_.Set(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z);
}

void AC_Character::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AC_Character::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void AC_Character::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void AC_Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AC_Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AC_Character::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, (Value * speed_));
	}
}

void AC_Character::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement in that direction
		AddMovementInput(Direction, (Value * speed_));
	}
}

void AC_Character::Attack()
{
	// We are now attacking, this will trigger the animation.
	is_attacking_ = true;

	// Make sure we have a target.
	if (current_target_ == nullptr)
		return;

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("Attack")));

	if (current_target_->ActorHasTag("Player"))
	{
		// Attack this player...
		AC_Character* target_player = Cast<AC_Character>(current_target_);
		
		// If the player is defending or has a defensive pickup, just return.
		if (!target_player->CanBeAttacked())
			return;

		if (target_player != nullptr)
		{
			// Push the target player back with the desired amount of force in the correct direction.
			const FVector force(attack_force_, attack_force_, attack_force_);
			FVector direction = target_player->GetActorLocation() - GetActorLocation();
			direction.Normalize();

			target_player->GetCharacterMovement()->Velocity += (force * direction);
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("PUSH")));
		}
	}
}

void AC_Character::StopAttack()
{
	is_attacking_ = false;
}

void AC_Character::Defend()
{
	can_be_attacked_ = false;
}

void AC_Character::StopDefend()
{
	can_be_attacked_ = true;
}

void AC_Character::Respawn()
{
	// If this player should be able to just constantly respawn back into the game.
	if (has_infinite_lives_)
	{
		// Teleport the player to the spawn position.
		SetActorLocation(spawn_position_);
		is_spawning_ = false;
	}
	// Otherwise, the player has a limited amount of lives.
	else
	{
		if (is_spawning_)
		{
			// If the player still has lives, respawn them.
			if ((lives_ + 1) > 0)
			{
				// Teleport the player to the spawn position.
				SetActorLocation(spawn_position_);
				is_spawning_ = false;
			}
			// Otherwise, the player has no lives left.
			else
				Super::Destroy();
		}
	}
}

void AC_Character::Raycast()
{
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	RV_TraceParams.bTraceComplex = true;
	RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;

	//Re-initialize hit info
	FHitResult RV_Hit(ForceInit);
	FVector end = GetActorLocation() + (ray_distance_ * GetActorForwardVector());

	//call GetWorld() from within an actor extending class
	GetWorld()->LineTraceSingleByChannel
	(
		RV_Hit, //result
		GetActorLocation(), //start
		end, //end
		ECC_Pawn, //collision channel
		RV_TraceParams
	);

	if (current_target_ != RV_Hit.GetActor())
		current_target_ = RV_Hit.GetActor();
}

void AC_Character::SetSpawningStatus(const bool value)
{
	is_spawning_ = value;
}

void AC_Character::SetCanBeAttacked(const bool value)
{
	can_be_attacked_ = value;
}

void AC_Character::SetCanUsePickups(const bool value)
{
	can_use_pickups_ = value;
}

void AC_Character::SetIndex(const int32 index)
{
	player_index_ = index;
}

void AC_Character::SetInfiniteLives(const bool value)
{
	has_infinite_lives_ = value;
}

void AC_Character::SetAttackState(const bool value)
{
	is_attacking_ = value;
}

void AC_Character::SetSpeed(const float speedMultiplier)
{
	speed_ = speedMultiplier;
}

void AC_Character::SetSpeedToNormal()
{
	speed_ = original_speed_;
}

void AC_Character::SetLives(int lives)
{
	lives_ = lives;
}

void AC_Character::SetSpawnPosition(const FVector value)
{
	spawn_position_ = value;
}

bool& AC_Character::IsSpawning()
{
	return is_spawning_;
}

bool& AC_Character::CanBeAttacked()
{
	return can_be_attacked_;
}

bool& AC_Character::CanUsePickups()
{
	return can_use_pickups_;
}

bool& AC_Character::IsAttacking()
{
	return is_attacking_;
}

int32& AC_Character::GetIndex()
{
	return player_index_;
}

bool& AC_Character::HasInfiniteLives()
{
	return has_infinite_lives_;
}

float& AC_Character::GetSpeed()
{
	return speed_;
}

int& AC_Character::GetLives()
{
	return lives_;
}