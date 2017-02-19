// Hilltown Games (C).

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_InvisibilityPickup.generated.h"

/**
 * 
 */
UCLASS()
class AMAZABALLZ_API AC_InvisibilityPickup : public AC_BasePickup
{
	GENERATED_BODY()

	protected:
		// Methods.
		// Overriding base pickup methods.
		virtual void PickupResponse(AActor* actor) override;
		virtual void PickupDestroy() override;

	private:
		// Attributes.
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")		// How long will the player be invisible for?
			float invisibility_timer_;

		bool picked_up_ = false;
		FTimerHandle unused_handle_;
		UStaticMeshComponent* mesh_ = nullptr;

		// Methods.
		void Visibility();
	
};
