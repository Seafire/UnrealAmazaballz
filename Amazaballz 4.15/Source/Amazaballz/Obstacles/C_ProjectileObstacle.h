// Hilltown Games (C).

/**
 * Projectile Obstacle
 * ===================
 *
 * Created:		2017/04/23 19:45
 * Class Name:	AC_ProjectileObstacle
 * Base Class:	AC_BaseObstacle
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides specific functionality for this projectile obstacle.
 */

#pragma once

#include "Obstacles/C_BaseObstacle.h"
#include "Obstacles/C_Projectile.h"
#include "C_ProjectileObstacle.generated.h"

/**
 * Provides specific functionality for this projectile obstacle.
 */
UCLASS()
class AMAZABALLZ_API AC_ProjectileObstacle : public AC_BaseObstacle
{
	GENERATED_BODY()
	
	protected:
		/**
		 * Provides a standard response for colliding with this obstacle.
		 * @param actor the actor that is colliding with this game object.
		 */
		virtual void ObstacleResponse(AActor* actor) override;

		/**
		 * Provides a standard response for exiting colliders with this obstacle.
		 * @param actor the actor that is no longer colliding with this game object.
		 */
		virtual void ObstacleLeft(AActor* actor) override;

		UPROPERTY(EditAnywhere, Category = "Obstacle Properties")	// How long will it take for the projectiles to fire?
			float projectile_delay_;

		UPROPERTY(EditAnywhere, Category = "Obstacle Properties")	// What projectiles should we fire?
			TArray<AActor*> projectiles_;

	private:
		FTimerDelegate timer_del_;
		FTimerHandle unused_handle_;

		/**
		 * Used when the projectiles should fire.
		 */
		void FireProjectiles();
};