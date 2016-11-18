// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "C_PowerUpInterface.h"
#include "C_BasePowerUp.h"
#include "C_SpeedBoostPowerUp.generated.h"

/**
 * 
 */
UCLASS()
class AMAZABALLZ_API AC_SpeedBoostPowerUp : public AC_BasePowerUp, public IC_PowerUpInterface
{
	GENERATED_BODY()
	
public:
	// Attributes.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Power Up")
		float speed_boost_;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed Power Up")
		bool test_bool_;

	// Methods.
	AC_SpeedBoostPowerUp();

	virtual float GetMultiplier_Implementation() override;

	virtual bool GetToggle_Implementation() override;

	virtual void PowerUp_Implementation(AActor* actor) override;

private:
	// Methods.
	// This will provide the unqiue power up response.
	virtual void UniqueCollisionResponse(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector HitLocation, FVector NormalImpulse, const FHitResult& Hit) override;
	
	//UFUNCTION(BlueprintCallable, Category = "Power Up Interface")
		//float GetMultiplier(const TScriptInterface<IC_PowerUpInterface> &target);

};
