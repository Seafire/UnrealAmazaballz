// Hilltown Games (C).

#pragma once

#include "Obstacles/C_BaseObstacle.h"
#include "C_PitObstacle.generated.h"

/**
 * 
 */
UCLASS()
class AMAZABALLZ_API AC_PitObstacle : public AC_BaseObstacle
{
	GENERATED_BODY()
	
	public:
		// Called every frame
		virtual void Tick(float DeltaSeconds) override;

	protected:
		// Methods.
		// Overriding base obstacle methods.
		virtual void ObstacleResponse(AActor* actor) override;
		virtual void ObstacleLeft(AActor* actor) override;

	private:
		// Attributes.
		UPROPERTY(EditAnywhere, Category = "Obstacle Properties", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))	// How fast the player will move when they interact with this obstacle? 0 = slow, 1 = normal speed.
			float speed_multiplier_;
};