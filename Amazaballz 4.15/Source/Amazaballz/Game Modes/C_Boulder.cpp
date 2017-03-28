// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_Boulder.h"

AC_Boulder::AC_Boulder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AC_Boulder::BeginPlay()
{
	Super::BeginPlay();
	
	mesh_ = FindComponentByClass<UStaticMeshComponent>();

	if (mesh_)
	{
		FBodyInstance* mesh_physics = mesh_->GetBodyInstance();
		mesh_physics->AddImpulse(mesh_physics->GetBodyMass() * starting_force_ * 0.01f, false);
	}
}

void AC_Boulder::BoulderResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag("Player");

	// If this actor is a player character.
	if (is_player)
	{
		// Destroy them.
		AC_Character* player = Cast<AC_Character>(actor);
		GetWorld()->DestroyActor(player);
	}
}