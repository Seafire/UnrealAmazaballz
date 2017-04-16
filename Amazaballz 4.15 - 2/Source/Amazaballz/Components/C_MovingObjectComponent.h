// Hilltown Games (C).

/*
 * Moving Object
 * =============
 * 
 * Created:		2016/11/11 20:40
 * Class Name:	UC_MovingObjectComponent
 * Base Class:	UActorComponent
 * Author(s):	Conor Paterson and Jason Mottershead
 * 
 * Purpose:		The moving object component will allow any actor to move along predefined
 *				waypoints at variable speed.
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
		UC_MovingObjectComponent();
		virtual void BeginPlay() override;
		virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	private:
		UPROPERTY(EditAnywhere, Category = "Move Object")	// How fast will the object move between the waypoints.
			float speed_;

		UPROPERTY(EditAnywhere, Category = "Move Object")	// The waypoints to move to.
			TArray<FVector4> local_waypoints_;

		AActor* actor_;
		TArray<FVector4>  global_waypoints_;				// The global waypoints that will take the object's position into consideration.
		int from_waypoint_index_;							// The current waypoint index.
		float percentage_between_waypoints_;				// How far we are from the next waypoint.

		void NextPoint();
		FVector CalculateMovement(float delta_time);

		/*
		 * Provides access to the percentage this component is to the next waypoint.
		 * @return float the percentage to the next waypoint.
		 */
		inline float get_percentage_to_waypoint() { return percentage_between_waypoints_; }
};