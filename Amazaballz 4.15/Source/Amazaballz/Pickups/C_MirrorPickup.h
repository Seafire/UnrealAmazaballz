// Hilltown Games (C).

#pragma once

#include "Pickups/C_BasePickup.h"
#include "Characters/C_Player.h"
#include "C_MirrorPickup.generated.h"

/**
 * 
 */
UCLASS()
class AMAZABALLZ_API AC_MirrorPickup : public AC_BasePickup
{
	GENERATED_BODY()
	
	protected:
		// Methods.
		// Overriding base pickup methods.
		virtual void PickupResponse(AActor* actor) override;
		virtual void PickupDestroy() override;

	private:
		// Attributes.
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")	// How long will the attacks of other players be reflected for?
			float mirror_timer_;

		bool picked_up_ = false;
		FTimerHandle unused_handle_;
		UStaticMeshComponent* mesh_ = nullptr;

		// Methods.
		void RemoveMirror();	
};