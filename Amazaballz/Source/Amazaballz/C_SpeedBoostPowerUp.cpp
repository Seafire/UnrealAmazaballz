// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "C_SpeedBoostPowerUp.h"

AC_SpeedBoostPowerUp::AC_SpeedBoostPowerUp()
{
	speed_boost_ = 1.0f;
}

void AC_SpeedBoostPowerUp::UniqueCollisionResponse(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector HitLocation, FVector NormalImpulse, const FHitResult& Hit)
{
	// Increase the speed of the player.
	// Cast the colliding actor to rolling ball somehow.
	// Get the rolling ball component????


	// RollingBall BP.Movement Speed  = new speed;
	// PowerUpInterface.Speed = new speed;
	OtherActor->GetClass()->ImplementsInterface(UC_PowerUpInterface::StaticClass());

}

float AC_SpeedBoostPowerUp::GetMultiplier_Implementation()
{
	return speed_boost_;
}

bool AC_SpeedBoostPowerUp::GetToggle_Implementation()
{
	return test_bool_;
}

void AC_SpeedBoostPowerUp::PowerUp_Implementation(AActor* actor)
{
	// Do in blueprints....

}

//float AC_SpeedBoostPowerUp::GetMultiplier(const TScriptInterface<IC_PowerUpInterface> &target)
//{
//	return target->GetMultiplier();
//}