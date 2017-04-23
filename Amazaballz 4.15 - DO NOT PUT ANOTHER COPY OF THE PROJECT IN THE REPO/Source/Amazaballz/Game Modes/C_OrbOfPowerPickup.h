// Hilltown Games (C).

/**
 * Orb Of Power Pickup
 * ===================
 *
 * Created:		2017/04/22 22:10
 * Class Name: 	AC_OrbOfPowerPickup
 * Base Class:	AC_BasePickup
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides a way for players to build up power.
 */

#pragma once

#include "Pickups/C_BasePickup.h"
#include "Components/C_PowerComponent.h"
#include "C_OrbOfPowerPickup.generated.h"

/**
 * Provides a way for players to build up power.
 */
UCLASS()
class AMAZABALLZ_API AC_OrbOfPowerPickup : public AC_BasePickup
{
	GENERATED_BODY()
	
	protected:
		/**
		 * Provides a standard response for colliding with this pickup.
		 * @param actor the actor that is colliding with this game object.
		 */
		virtual void PickupResponse(AActor* actor) override;

		/**
		 * Provides a standard response when the player has picked it up.
		 */
		virtual void PickupDestroy() override;

		void ApplyPickupEffect() override;
		void UndoPickupEffect() override;

	private:
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")		// How much power palpatine?
			float amount_of_power_ = 10.0f;	
};