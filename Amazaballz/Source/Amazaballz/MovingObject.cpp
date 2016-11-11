// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "MovingObject.h"


// Sets default values
AMovingObject::AMovingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root_ = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = root_;

	mesh_ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh_->AttachTo(RootComponent);

	running_time_ = 0.0f;
}

// Called when the game starts or when spawned
void AMovingObject::BeginPlay()
{
	Super::BeginPlay();
	
	//components_ = GetComponents().Array();

	for (int i = 0; i < local_waypoints_.Num(); i++)
	{
		global_waypoints_.Emplace(local_waypoints_[i] + GetActorLocation());
	}

	/*if (components_.Num() != 0)
	{
		for (int i = 0; i < components_.Num(); i++)
		{
			UStaticMeshComponent* temp_static_mesh = Cast<UStaticMeshComponent>(components_[i]);

			if (temp_static_mesh)
			{
				static_mesh_ = temp_static_mesh;
			}
		}
	}*/
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

	FVector new_location = GetActorLocation();
	float delta_height = (FMath::Sin(running_time_ + deltaTime) - FMath::Sin(running_time_));
	new_location.Y += (delta_height * speed_);
	running_time_ += deltaTime;
	SetActorLocation(new_location);

	/*FVector velocity = CalculateMovement(deltaTime);
	AddActorLocalOffset(velocity);

	if (root_)
	{
		root_->SetWorldLocation(GetActorLocation());
	}*/

	//this->UpdateComponentTransforms();
	
	//if (static_mesh_)
	//{
	//	//static_mesh_->UpdateChildTransforms();
	//	//if(static_mesh_->Transform)
	//	static_mesh_->SetWorldTransform(GetTransform());
	//	static_mesh_->AddLocalOffset(GetActorLocation() - static_mesh_->GetComponentLocation());
	//}

}