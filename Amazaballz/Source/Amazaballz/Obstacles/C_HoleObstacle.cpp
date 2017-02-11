// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "C_HoleObstacle.h"

void AC_HoleObstacle::Respawn()
{
	mesh_->GetBodyInstance()->SetInstanceSimulatePhysics(true);
	
	FRotator rot(0.0f, 0.0f, 0.0f);
	player_controller_ = GetWorld()->SpawnActor<APlayerController>(APlayerController::StaticClass(), FVector::ZeroVector, rot);

	if (destroyed_after_use_)
		Super::Destroy();
}

void AC_HoleObstacle::ObstacleResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);
	UStaticMeshComponent* pickup_mesh_ = FindComponentByClass<UStaticMeshComponent>();
	mesh_ = actor->FindComponentByClass<UStaticMeshComponent>();
	player_controller_ = static_cast<APlayerController*>(actor);

	// If this actor is a player character.
	if (is_player)
	{
		// If the mesh exists.
		if (mesh_)
		{
			if (player_controller_)
			{
				// Reset the speed of the player.
				mesh_->SetPhysicsLinearVelocity(FVector::ZeroVector);

				if (pickup_mesh_ && destroyed_after_use_)
					pickup_mesh_->SetVisibility(false);

				if (mesh_->GetBodyInstance()->IsInstanceSimulatingPhysics())
					mesh_->GetBodyInstance()->SetInstanceSimulatePhysics(false);

				// Enable player input after a set time.
				GetWorldTimerManager().SetTimer(unused_handle_, this, &AC_HoleObstacle::Respawn, death_delay_, false);
				
			}
		}
	}
}

void AC_HoleObstacle::ObstacleLeft()
{
	// We could have something extra like a particle effect or something?
	// Destroy this pickup.
	//Super::Destroy();
}