// Hilltown Games (C).

#pragma once

#include "Obstacles/C_BaseObstacle.h"
#include "C_HoleObstacle.generated.h"

/**
 * 
 */
UCLASS()
class AMAZABALLZ_API AC_HoleObstacle : public AC_BaseObstacle
{
	GENERATED_BODY()

	protected:
		// Methods.
		// Overriding base obstacle methods.
		virtual void ObstacleResponse(AActor* actor) override;
		virtual void ObstacleLeft(AActor* actor) override;

		// Attributes.
		UPROPERTY(EditAnywhere, Category = "Obstacle Properties", meta = (ClampMin = "0.0", ClampMax = "3.0", UIMin = "0.0", UIMax = "3.0"))	// How long will it take for the player to respawn?
			float death_delay_;

	private:
		FTimerDelegate timer_del_;
		FTimerHandle unused_handle_;
		AActor* player_actor_;

		// Methods.
		//UFUNCTION()
		void Respawn(UStaticMeshComponent* mesh);
};