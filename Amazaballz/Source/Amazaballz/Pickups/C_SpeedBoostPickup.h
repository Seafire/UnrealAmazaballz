// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_SpeedBoostPickup.generated.h"

/**
 * 
 */
UCLASS()
class AMAZABALLZ_API AC_SpeedBoostPickup : public AC_BasePickup
{
	GENERATED_BODY()

	protected:
		// Methods.
		// Overriding base pickup methods.
		virtual void PickupResponse(AActor* actor) override;
		virtual void PickupDestroy() override;

	private:
		// Attributes.
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")	// Allow this attribute to be edited anywhere within Unreal 4 under the heading Speed Pickup.
			float speed_multiplier_;							// How fast will the player will move.
	
};
