// Fill out your copyright notice in the Description page of Project Settings.

/*

	Moving Object
	=============

	Created:	2016/11/11 20:40:10
	Class Name: UC_MovingObjectComponent
	Base Class:	UActorComponent
	Author(s):	Conor Paterson and Jason Mottershead

	Purpose:	To provide any standard game object with an easy to use and plot waypoint system with adjustable speed.

*/

#pragma once

#include <vector>
#include "Components/ActorComponent.h"
#include "C_MovingObjectComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AMAZABALLZ_API UC_MovingObjectComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UC_MovingObjectComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	private:
		// Attributes.
		UPROPERTY(EditAnywhere, Category = "Move Object")	// Allow this attribute to be edited anywhere within Unreal 4 under the heading Move Object.
			float speed_;										// How fast will the object move between the waypoints.

		UPROPERTY(EditAnywhere, Category = "Move Object")	// Allow this attribute to be edited anywhere within Unreal 4 under the heading Move Object.
			TArray<FVector4> local_waypoints_;					// The waypoints to move to.

		AActor* actor_;
		TArray<FVector4>  global_waypoints_;	// The global waypoints that will take the object's position into consideration.
		int from_waypoint_index_;				// The current waypoint index.
		float percentage_between_waypoints_;	// How far we are from the next waypoint.

		// Methods.
		// This will setup the next point index for the waypoints.
		void NextPoint();

		// This will calculate the velocity to the next waypoint.
		FVector CalculateMovement(float delta_time);

		// Getters/Setters.
		// This will allow us to get the current percentage to the next waypoint.
		inline float get_percentage_to_waypoint() { return percentage_between_waypoints_; }
};