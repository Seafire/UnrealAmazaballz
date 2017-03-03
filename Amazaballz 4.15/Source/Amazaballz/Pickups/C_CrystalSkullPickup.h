// Hilltown Games (C).

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_CrystalSkullPickup.generated.h"

/**
 * 
 */
UCLASS()
class AMAZABALLZ_API AC_CrystalSkullPickup : public AC_BasePickup
{
	GENERATED_BODY()
	
	protected:
		// Methods.
		// Overriding base pickup methods.
		virtual void PickupResponse(AActor* actor) override;
		virtual void PickupDestroy() override;

	private:
		// Attributes.
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")		// How many lives will this skull restore?
			int amount_of_lives_;
};
