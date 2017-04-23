// Hilltown Games (C).

/*
 * Disable Pickup
 * ==============
 *
 * Created:		2017/03/04 19:45
 * Class Name:	AC_InvisibilityPickup
 * Base Class:	AC_BasePickup
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides more specific functionality for invisibility pickup.
 */

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_InvisibilityPickup.generated.h"

UCLASS()
class AMAZABALLZ_API AC_InvisibilityPickup : public AC_BasePickup
{
	GENERATED_BODY()

	protected:
		virtual void PickupResponse(AActor* actor) override;
		virtual void PickupDestroy() override;

		void ApplyPickupEffect() override;
		void UndoPickupEffect() override;

	private:
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")		// How long will the player be invisible for?
			float invisibility_timer_;

		bool picked_up_ = false;
		FTimerHandle unused_handle_;
		AC_Character* interacting_player_;

		void Visibility();
	
};
