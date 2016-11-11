// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "GameFramework/Actor.h"
#include "MovingObject.generated.h"

UCLASS()
class AMAZABALLZ_API AMovingObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Attributes.
	UPROPERTY(EditAnywhere, Category = "Move Object")
	float speed_;										// How fast will the object move between the points.

	UPROPERTY(EditAnywhere, Category = "Move Object")
	TArray<FVector4> local_waypoints_;					// The points to move to.

	UPROPERTY(EditAnywhere, Category = "Move Object")
	UShapeComponent* root_;

	UPROPERTY(EditAnywhere, Category = "Move Object")
	UStaticMeshComponent* mesh_;

	float running_time_;

	// Sets default values for this actor's properties
	AMovingObject();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// This will setup the next point for the waypoints.
	void NextPoint();

	// This will calculate the next waypoint to move to.
	FVector CalculateMovement(float tick);
	
	// Getters/Setters.
	// This will allow us to get the current percentage to the next waypoint.
	inline float get_percentage_to_waypoint() { return percentage_between_waypoints_; }
	
private:
	// Attributes.
	TArray<FVector4>  global_waypoints_;
	//TArray<USceneComponent*> children_components_;
	TArray<UActorComponent*> components_;
	int from_waypoint_index_;
	float percentage_between_waypoints_;

};
