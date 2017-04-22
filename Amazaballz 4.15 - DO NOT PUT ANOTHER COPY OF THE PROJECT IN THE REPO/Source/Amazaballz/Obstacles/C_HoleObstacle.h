// Hilltown Games (C).

/*
 * Hole Obstacle
 * =============
 *
 * Created:		2017/03/04 19:45
 * Class Name:	AC_HoleObstacle
 * Base Class:	AActor
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides more specific functionality for hole obstacles.
 */

#pragma once

#include "Obstacles/C_BaseObstacle.h"
#include "C_HoleObstacle.generated.h"

UCLASS()
class AMAZABALLZ_API AC_HoleObstacle : public AC_BaseObstacle
{
	GENERATED_BODY()

	protected:
		virtual void ObstacleResponse(AActor* actor) override;
		virtual void ObstacleLeft(AActor* actor) override;

		UPROPERTY(EditAnywhere, Category = "Obstacle Properties", meta = (ClampMin = "0.0", ClampMax = "3.0", UIMin = "0.0", UIMax = "3.0"))	// How long will it take for the player to respawn?
			float death_delay_;

	private:
		FTimerDelegate timer_del_;
		FTimerHandle unused_handle_;
		AActor* player_actor_;

		void Respawn();
};