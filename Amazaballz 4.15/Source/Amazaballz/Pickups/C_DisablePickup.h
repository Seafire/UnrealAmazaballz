// Hilltown Games (C).

/*
 * Disable Pickup
 * ==============
 *
 * Created:		2017/03/04 19:45
 * Class Name:	AC_DisablePickup
 * Base Class:	AC_BasePickup
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides more specific functionality for disable pickup.
 */

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_DisablePickup.generated.h"

UCLASS()
class AMAZABALLZ_API AC_DisablePickup : public AC_BasePickup
{
	GENERATED_BODY()
	
	protected:
		virtual void PickupResponse(AActor* actor) override;
		virtual void PickupDestroy() override;

		void ApplyPickupEffect() override;
		void UndoPickupEffect() override;

	private:
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")	// How long will all of the other players not have access to pickups for?
			float disable_timer_;

		bool picked_up_ = false;
		FTimerHandle unused_handle_;
		//std::vector<AC_Player*> players_;
		//std::vector<AC_Character*> players_;
		AC_Character* interacting_player_;

		void EnablePickups();	
};
