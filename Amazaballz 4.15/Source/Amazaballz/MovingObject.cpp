// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "MovingObject.h"

/*

	Overview
	========
	This will be used to initialise attributes and decide update usage.

*/
AMovingObject::AMovingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialising the root component.
	root_ = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = root_;

	// Initialising the static mesh component.
	mesh_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh_->AttachTo(RootComponent);
}

/*

	Overview
	========
	This method is called when the game starts or when this object is spawned in.

*/
void AMovingObject::BeginPlay()
{
	// Call base Actor begin play.
	Super::BeginPlay();

	if (local_waypoints_.Num() == 0)	return;

	// Loop through each of the waypoints.
	for (int i = 0; i < local_waypoints_.Num(); i++)
	{
		// Add a new waypoint to the global waypoints.
		global_waypoints_.Emplace(local_waypoints_[i] + GetActorLocation());
	}
}

/*

	Overview
	========
	Here we just decide what happens when the object has reached it's current destination.

*/
void AMovingObject::NextPoint()
{
	// Reset the percentage to the next waypoint.
	percentage_between_waypoints_ = 0.0f;

	// Increment where we are travelling from.
	from_waypoint_index_++;

	// If where we are travelling from is greater than the amount of waypoints we have provided.
	if (from_waypoint_index_ > (global_waypoints_.Num() - 1))
	{
		// Reset back to the starting waypoint.
		from_waypoint_index_ = 0;
	}
}

/*

	Overview
	========
	This will be used to initialise attributes and decide update usage.

	Params
	======
	float tick	-	This is used to pass along delta time from the update method and
					adjust object speed accordingly.

*/
FVector AMovingObject::CalculateMovement(float delta_time)
{
	// Initialise where we are travelling to.
	int to_waypoint_index = 0;

	// If where we are travelling from is less than the amount of waypoints we have provided.
	if (from_waypoint_index_ < (global_waypoints_.Num() - 1))
	{
		// Set where we are travelling to, to be the next waypoint.
		to_waypoint_index = from_waypoint_index_ + 1;
	}
	// Otherwise, if where we are travelling from is equal to the amount of waypoints we have provided.
	else if (from_waypoint_index_ == (global_waypoints_.Num() - 1))
	{
		// Reset back to the starting waypoint.
		to_waypoint_index = 0;
	}

	// Calculate how far the object is from the next waypoint.
	float distance_between_waypoints = FVector::Dist(global_waypoints_[from_waypoint_index_], global_waypoints_[to_waypoint_index]);

	// Calculate the percentage of the distance travelled between the next waypoint.
	percentage_between_waypoints_ += delta_time * (speed_ / distance_between_waypoints);

	// Calculate the new position for the object.
	FVector new_position = FMath::Lerp(global_waypoints_[from_waypoint_index_], global_waypoints_[to_waypoint_index], percentage_between_waypoints_);

	// If the percentage to the next waypoint is greater than 1 (i.e. 100%).
	if (percentage_between_waypoints_ >= 1.0f)
	{
		// Setup the next waypoint.
		NextPoint();
	}

	// Return the new velocity for the object.
	return (new_position - GetActorLocation());
}

/*

	Overview
	========
	This will be used to initialise attributes and decide update usage.

	Params
	======
	float delta_time	-	Contains delta time for the last time the game was updated.

*/
void AMovingObject::Tick(float delta_time)
{
	// Call base Actor tick method.
	Super::Tick(delta_time);
	
	if (!global_waypoints_.Num() == 0)
	{
		// Calculate the new velocity value.
		FVector velocity = CalculateMovement(delta_time);

		// Setup the new position.
		FVector new_position = GetActorLocation();

		// Add the velocity onto the new position.
		new_position += velocity;

		// Set the object to the new position.
		SetActorLocation(new_position);
	}
}