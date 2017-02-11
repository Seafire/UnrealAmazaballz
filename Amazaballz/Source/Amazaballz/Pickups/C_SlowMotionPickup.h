// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_SlowMotionPickup.generated.h"

/**
 * 
 */
UCLASS()
class AMAZABALLZ_API AC_SlowMotionPickup : public AC_BasePickup
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
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")																				// How long will all of the players be in slow motion for?
			float slow_motion_timer_;

		UPROPERTY(EditAnywhere, Category = "Pickup Properties", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))	// How slow will the players be?
			float slow_motion_factor_;

		bool picked_up_ = false;
		FTimerHandle unused_handle_;
		UStaticMeshComponent* mesh_ = nullptr;

		// Methods.
		void NormalSpeed();
};
