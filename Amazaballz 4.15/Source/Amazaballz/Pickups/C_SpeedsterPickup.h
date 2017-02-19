// Hilltown Games (C).

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_SpeedsterPickup.generated.h"

/**
 * 
 */
UCLASS()
class AMAZABALLZ_API AC_SpeedsterPickup : public AC_BasePickup
{
	GENERATED_BODY()
	
	public:
		// Called every frame
		virtual void Tick(float DeltaSeconds) override;

	protected:
		// Methods.
		// Overriding base pickup methods.
		virtual void PickupResponse(AActor* actor) override;
		virtual void PickupDestroy() override;

	private:
		// Attributes.
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")																							// How long will player's speed be affected for?
			float speedster_timer_;

		UPROPERTY(EditAnywhere, Category = "Pickup Properties", meta = (ClampMin = "0.0", ClampMax = "50.0", UIMin = "0.0", UIMax = "50.0"))			// How will the player's speed be affected?
			float speedster_factor_;

		bool picked_up_ = false;
		FTimerHandle unused_handle_;
		UStaticMeshComponent* mesh_ = nullptr;

		// Methods.
		void NormalSpeed();
};