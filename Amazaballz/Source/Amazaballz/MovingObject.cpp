// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "MovingObject.h"


// Sets default values
AMovingObject::AMovingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AMovingObject::BeginPlay()
{
	Super::BeginPlay();
	
	for (int i = 0; i < local_waypoints_.Num(); i++)
	{
		global_waypoints_.Emplace(local_waypoints_[i] + GetActorLocation());
	}
}

void AMovingObject::NextPoint()
{
	percentage_between_waypoints_ = 0.0f;

	from_waypoint_index_++;

	if (from_waypoint_index_ > (global_waypoints_.Num() - 1))
	{
		from_waypoint_index_ = 0;
	}
}

FVector AMovingObject::CalculateMovement(float tick)
{
	int to_waypoint_index = 0;

	if (from_waypoint_index_ < (global_waypoints_.Num() - 1))
	{
		to_waypoint_index = from_waypoint_index_ + 1;
	}
	else if (from_waypoint_index_ == (global_waypoints_.Num() - 1))
	{
		to_waypoint_index = 0;
	}

	float distance_between_waypoints = FVector::Dist(global_waypoints_[from_waypoint_index_], global_waypoints_[to_waypoint_index]);

	percentage_between_waypoints_ += tick * (speed_ / distance_between_waypoints);

	FVector new_position = FMath::Lerp(global_waypoints_[from_waypoint_index_], global_waypoints_[to_waypoint_index], percentage_between_waypoints_);

	if (percentage_between_waypoints_ >= 1.0f)
	{
		NextPoint();
	}

	return (new_position - GetActorLocation());
}

// Called every frame
void AMovingObject::Tick( float deltaTime )
{
	Super::Tick( deltaTime );


	FVector velocity = CalculateMovement(deltaTime);
	AddActorLocalOffset(velocity);
}