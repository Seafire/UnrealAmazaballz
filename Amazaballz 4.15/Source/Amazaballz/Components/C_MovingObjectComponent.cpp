// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_MovingObjectComponent.h"

/*
 * Sets the default values.
 */
UC_MovingObjectComponent::UC_MovingObjectComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	actor_ = GetOwner();
}

/*
 * Called when the game starts.
 */
void UC_MovingObjectComponent::BeginPlay()
{
	Super::BeginPlay();

	// If there are no waypoints, do nothing else.
	if (local_waypoints_.Num() == 0)	return;

	// Loop through each of the waypoints.
	for (int i = 0; i < local_waypoints_.Num(); i++)
	{
		// Add a new waypoint to the global waypoints.
		global_waypoints_.Emplace(local_waypoints_[i] + actor_->GetActorLocation());
	}
}

/*
 * Here we just decide what happens when the object has reached it's current destination.
 */
void UC_MovingObjectComponent::NextPoint()
{
	percentage_between_waypoints_ = 0.0f;
	from_waypoint_index_++;

	// If where we are travelling from is greater than the amount of waypoints we have provided.
	if (from_waypoint_index_ > (global_waypoints_.Num() - 1))
	{
		// Reset back to the starting waypoint.
		from_waypoint_index_ = 0;
	}
}

/*
 * This will be used to initialise attributes and decide update usage.
 * @param tick the time passed since the last frame update.
 */
FVector UC_MovingObjectComponent::CalculateMovement(float delta_time)
{
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
	percentage_between_waypoints_ += delta_time * (speed_ / distance_between_waypoints);
	FVector new_position = FMath::Lerp(global_waypoints_[from_waypoint_index_], global_waypoints_[to_waypoint_index], percentage_between_waypoints_);

	// If the percentage to the next waypoint is greater than 1 (i.e. 100%).
	if (percentage_between_waypoints_ >= 1.0f)
	{
		// Setup the next waypoint.
		NextPoint();
	}

	// Return the new velocity for the object.
	return (new_position - actor_->GetActorLocation());
}

/*
 * Called every frame.
 * @param DeltaTime the time passed since the last frame update.
 * @param TickType what type of update this component uses, i.e. if we are paused, or running in the editor.
 * @param ThisTickFunction internal tick function struct that cause this to run.
 */
void UC_MovingObjectComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// If there are global waypoints.
	if (!global_waypoints_.Num() == 0)
	{
		// Calculate the new velocity value.
		FVector velocity = CalculateMovement(DeltaTime);

		// Setup the new position.
		FVector new_position = actor_->GetActorLocation();

		// Add the velocity onto the new position.
		new_position += velocity;

		// Set the object to the new position.
		actor_->SetActorLocation(new_position);
	}
}

