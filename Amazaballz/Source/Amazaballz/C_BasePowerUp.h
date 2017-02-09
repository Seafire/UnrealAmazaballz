// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MovingObject.h"
#include "GameFramework/Actor.h"
#include "C_BasePowerUp.generated.h"

UCLASS()
class AMAZABALLZ_API AC_BasePowerUp : public AMovingObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AC_BasePowerUp();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

protected:
	// Methods.
	// Collision checks.
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	// Provides standard collision responses for power ups (removing from the scene.)
	void StandardCollisionResponse(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector HitLocation, FVector NormalImpulse, const FHitResult& Hit);

	//UFUNCTION()
	// Pure virtual function.
	// Inheriting power ups must provide unique power ups response.
	// Provides unique collision responses for the power ups.
	virtual void UniqueCollisionResponse(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector HitLocation, FVector NormalImpulse, const FHitResult& Hit)
	PURE_VIRTUAL(AC_BasePickup::UniqueCollisionResponse(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector HitLocation, FVector NormalImpulse, const FHitResult& Hit), ;);
	
};
