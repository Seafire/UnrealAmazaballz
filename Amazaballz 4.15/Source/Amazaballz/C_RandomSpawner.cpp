// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_RandomSpawner.h"

AC_RandomSpawner::AC_RandomSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AC_RandomSpawner::BeginPlay()
{
	Super::BeginPlay();

	// Spawns a random actor here.
	ChooseRandomActor();
}

void AC_RandomSpawner::ChooseRandomActor()
{
	int random_index = FMath::RandRange(0, (actors_.Num() - 1));
	
	FActorSpawnParameters spawn_info;
	spawn_info.Owner = this;
	spawn_info.Instigator = Instigator;

	FVector spawn_location = GetActorLocation();
	FRotator spawn_rotation = FRotator::ZeroRotator;

	AActor* new_object = GetWorld()->SpawnActor<AActor>(actors_[random_index], spawn_location, spawn_rotation, spawn_info);
}