// Hilltown Games (C).

/*
 * Speed Boost Pickup
 * ==================
 *
 * Created:		2017/03/04 19:45
 * Class Name:	AC_SpeedBoostPickup
 * Base Class:	AC_BasePickup
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides more specific functionality for speed boost pickup.
 */

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_SpeedBoostPickup.generated.h"

UCLASS()
class AMAZABALLZ_API AC_SpeedBoostPickup : public AC_BasePickup
{
	GENERATED_BODY()

	public:
		virtual void BeginPlay() override;

	protected:
		virtual void PickupResponse(AActor* actor) override;
		virtual void PickupDestroy() override;

		void ApplyPickupEffect() override;
		void UndoPickupEffect() override;

	private:
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")	// How fast the player will move when they interact with this pickup.
			float speed_multiplier_;

		FTimerHandle unused_handle_;
		float original_speed_ = 0.0f, original_acceleration_ = 0.0f;
		AC_Character* interacting_player_ = nullptr;

		void NormalSpeed();
};