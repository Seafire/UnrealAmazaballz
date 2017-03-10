// Hilltown Games (C).

/*
 * Crystal Skull Pickup
 * ====================
 *
 * Created:		2017/02/12 20:58
 * Class Name: 	AC_CrystalSkullPickup
 * Base Class:	AC_BasePickup
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides the user with a way to gain lives.
 */

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_CrystalSkullPickup.generated.h"

UCLASS()
class AMAZABALLZ_API AC_CrystalSkullPickup : public AC_BasePickup
{
	GENERATED_BODY()
	
	protected:
		virtual void PickupResponse(AActor* actor) override;
		virtual void PickupDestroy() override;

	private:
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")		// How many lives will this skull restore?
			int amount_of_lives_;
};
