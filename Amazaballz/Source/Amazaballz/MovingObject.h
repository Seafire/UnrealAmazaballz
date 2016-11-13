// Fill out your copyright notice in the Description page of Project Settings.

/*

	Moving Object
	=============

	Created:	2016/11/11 20:40:10
	Class Name: AMovingObject
	Base Class:	AActor
	Author(s):	Conor Paterson and Jason Mottershead

	Purpose:	To provide any standard game object with an easy to use and plot waypoint system with adjustable speed.

*/

// Header guard.
#pragma once

// Includes here.
#include <vector>
#include "GameFramework/Actor.h"
#include "MovingObject.generated.h"

UCLASS()
class AMAZABALLZ_API AMovingObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Attributes.
	UPROPERTY(EditAnywhere, Category = "Move Object")	// Allow this attribute to be edited anywhere within Unreal 4 under the heading Move Object.
	float speed_;										// How fast will the object move between the waypoints.

	UPROPERTY(EditAnywhere, Category = "Move Object")	// Allow this attribute to be edited anywhere within Unreal 4 under the heading Move Object.
	TArray<FVector4> local_waypoints_;					// The waypoints to move to.

	UPROPERTY(EditAnywhere, Category = "Move Object")	// Allow this attribute to be edited anywhere within Unreal 4 under the heading Move Object.
	UShapeComponent* root_;								// The root collider component of the moving object.

	UPROPERTY(EditAnywhere, Category = "Move Object")	// Allow this attribute to be edited anywhere within Unreal 4 under the heading Move Object.
	UStaticMeshComponent* mesh_;						// The static mesh component to render for the moving object.
	
	// Methods.
	// Assigning attribute values.
	AMovingObject();

	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// Called every frame.
	virtual void Tick(float delta_time) override;

	// This will setup the next point index for the waypoints.
	void NextPoint();

	// This will calculate the velocity to the next waypoint.
	FVector CalculateMovement(float delta_time);
	
	// Getters/Setters.
	// This will allow us to get the current percentage to the next waypoint.
	inline float get_percentage_to_waypoint() { return percentage_between_waypoints_; }
	
private:
	// Attributes.
	TArray<FVector4>  global_waypoints_;	// The global waypoints that will take the object's position into consideration.
	int from_waypoint_index_;				// The current waypoint index.
	float percentage_between_waypoints_;	// How far we are from the next waypoint.

};
