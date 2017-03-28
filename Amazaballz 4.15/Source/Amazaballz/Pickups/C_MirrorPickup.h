// Hilltown Games (C).

/*
 * Mirror Pickup
 * =============
 *
 * Created:		2017/03/04 19:45
 * Class Name:	AC_MirrorPickup
 * Base Class:	AC_BasePickup
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides more specific functionality for mirror pickup.
 */

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_MirrorPickup.generated.h"

UCLASS()
class AMAZABALLZ_API AC_MirrorPickup : public AC_BasePickup
{
	GENERATED_BODY()
	
	protected:
		virtual void PickupResponse(AActor* actor) override;
		virtual void PickupDestroy() override;

	private:
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")	// How long will the attacks of other players be reflected for?
			float mirror_timer_;

		bool picked_up_ = false;
		FTimerHandle unused_handle_;
		AC_Character* interacting_player_;

		void RemoveMirror();	
};