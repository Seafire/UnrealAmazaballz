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
	Push(starting_force_);

	TArray<AActor*> players;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AC_Character::StaticClass(), players);
	number_of_players_ = players.Num();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("Num of players %i"), number_of_players_));
	}
}

void AC_Boulder::Push(const FVector force)
{
	if (mesh_)
	{
		FBodyInstance* mesh_physics = mesh_->GetBodyInstance();
		mesh_physics->AddImpulse(mesh_physics->GetBodyMass() * force * 0.01f, false);
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
		PlayerResponse(player);
	}
	// Otherwise, it is an obstacle that needs to be destroyed.
	else
	{
		ObstacleResponse(actor);
	}
}

void AC_Boulder::PlayerResponse(AC_Character* player)
{
	if (number_of_players_ > 0)
	{
		number_of_players_--;
		GetWorld()->DestroyActor(player);
	}
}

void AC_Boulder::ObstacleResponse(AActor* actor)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("Destroying Obstacle...")));
	}
	GetWorld()->DestroyActor(actor);
}

void AC_Boulder::Tick(float DeltaSeconds)
{
}