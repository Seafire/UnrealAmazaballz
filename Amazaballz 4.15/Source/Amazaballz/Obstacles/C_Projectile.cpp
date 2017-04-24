// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_Projectile.h"

void AC_Projectile::Init(const FVector direction, const float speed)
{
	direction_ = direction;
	speed_ = speed;
	actor_ = GetOwner();

	// Every second increment the lifetime of this projectile.
	GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_Projectile::LifeTimeCounter, 1.0f, true);
}

void AC_Projectile::LifeTimeCounter()
{
	if(current_lifetime_ < lifetime_)
		current_lifetime_++;
}

void AC_Projectile::ProjectileResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);

	// If this actor is a player character.
	if (is_player)
	{
		AC_Character* player = Cast<AC_Character>(actor);
		UStaticMeshComponent* mesh = FindComponentByClass<UStaticMeshComponent>();

		// Kill the player.
		player->SetSpawningStatus(true);
		if (!player->HasInfiniteLives())
			player->SetLives(player->GetLives() - 1);
	}
}

void AC_Projectile::DestroyProjectile()
{
	Super::Destroy();
}

void AC_Projectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If this projectile has been alive for too long, destroy it.
	if (current_lifetime_ > lifetime_)
		DestroyProjectile();

	FVector velocity = (direction_ * speed_);
	FVector new_position = actor_->GetActorLocation();

	new_position += velocity;
	actor_->SetActorLocation(new_position);
}