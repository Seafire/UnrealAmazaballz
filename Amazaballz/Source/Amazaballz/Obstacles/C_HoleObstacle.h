// Fill out your copyright notice in the Description page of Project Settings.

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
		// Overriding base pickup methods.
		virtual void ObstacleResponse(AActor* actor) override;
		virtual void ObstacleLeft() override;

		// Attributes.
		UPROPERTY(EditAnywhere, Category = "Obstacle Properties", meta = (ClampMin = "0.0", ClampMax = "3.0", UIMin = "0.0", UIMax = "3.0"))	// How long will it take for the player to respawn?
			float death_delay_;

	private:
		FTimerHandle unused_handle_;

		// Methods.
		void Respawn();
};