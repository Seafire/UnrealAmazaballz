// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickups/C_BasePickup.h"
#include "C_FreezePickup.generated.h"

/**
 * 
 */
UCLASS()
class AMAZABALLZ_API AC_FreezePickup : public AC_BasePickup
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
		UPROPERTY(EditAnywhere, Category = "Pickup Properties")	// How long will all of the other players be frozen for?
			float freeze_timer_;

		bool picked_up_ = false;
		FTimerHandle unused_handle_;
		UStaticMeshComponent* mesh_ = nullptr;

		// Methods.
		void UnFreeze();
};