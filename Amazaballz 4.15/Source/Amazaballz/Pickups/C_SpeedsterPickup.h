// Hilltown Games (C).

/*
 * Speedster Pickup
 * ================
 *
 * Created:		2017/03/04 19:45
 * Class Name:	AC_SpeedsterPickup
 * Base Class:	AC_BasePickup
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides more specific functionality for speedster pickup.
 */

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_SpeedsterPickup.generated.h"

UCLASS()
class AMAZABALLZ_API AC_SpeedsterPickup : public AC_BasePickup
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
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")																							// How long will player's speed be affected for?
			float speedster_timer_;

		UPROPERTY(EditAnywhere, Category = "Pickup Properties", meta = (ClampMin = "0.0", ClampMax = "50.0", UIMin = "0.0", UIMax = "50.0"))			// How will the player's speed be affected?
			float speedster_factor_;

		bool picked_up_ = false;
		FTimerHandle unused_handle_;
		float original_speed_ = 0.0f, original_acceleration_ = 0.0f;
		AC_Character* interacting_player_ = nullptr;

		void NormalSpeed();
};