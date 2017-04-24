// Hilltown Games (C).

/**
 * Projectile
 * ==========
 *
 * Created:		2017/04/23 23:42
 * Class Name:	AC_Projectile
 * Base Class:	AC_BaseObstacle
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides specific functionality for this projectile.
 */

#pragma once

#include "Obstacles/C_BaseObstacle.h"
#include "C_Projectile.generated.h"

/**
 * Provides specific functionality for this projectile.
 */
UCLASS()
class AMAZABALLZ_API AC_Projectile : public AC_BaseObstacle
{
	GENERATED_BODY()
	
	public:
		/**
		 * Sets the default values.
		 * @param direction the direction this projectile should fire in.
		 * @param speed how fast this projectile should travel.
		 */
		void Init(const FVector direction, const float speed);

		/**
		 * Provides standard responses to actors when this projectile collides with them.
		 * @param actor the actor this projectile has collided with.
		 */
		UFUNCTION(BlueprintCallable, Category = "Obstacles")
			void ProjectileResponse(AActor* actor);

		/**
		 * What happens when we destroy this project.
		 */
		void DestroyProjectile();

		/**
		 * Called every frame.
		 * @param DeltaTime the time passed since the last frame update.
		 */
		virtual void Tick(float DeltaTime) override;

	private:
		const int lifetime_ = 15;
		int current_lifetime_ = 0;
		float speed_ = 0.0f;
		FVector direction_;
		FTimerDelegate timer_del_;
		FTimerHandle unused_handle_;
		AActor* actor_;

		void LifeTimeCounter();
};