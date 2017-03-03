// Hilltown Games (C).

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_DisablePickup.generated.h"

/**
 * 
 */
UCLASS()
class AMAZABALLZ_API AC_DisablePickup : public AC_BasePickup
{
	GENERATED_BODY()
	
	protected:
		// Methods.
		// Overriding base pickup methods.
		virtual void PickupResponse(AActor* actor) override;
		virtual void PickupDestroy() override;

	private:
		// Attributes.
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")	// How long will all of the other players not have access to pickups for?
			float disable_timer_;

		bool picked_up_ = false;
		FTimerHandle unused_handle_;
		UStaticMeshComponent* mesh_ = nullptr;
		std::vector<AC_Player*> players_;

		// Methods.
		void EnablePickups();	
};
