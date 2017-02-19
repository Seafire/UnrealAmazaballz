// Hilltown Games (C).

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
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")	// How fast the player will move when they interact with this pickup.
			float speed_multiplier_;
};