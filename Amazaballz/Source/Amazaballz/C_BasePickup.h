// Fill out your copyright notice in the Description page of Project Settings.

/*

	Base Pickup
	===========

	Created:	2016/11/18 15:40:10
	Class Name: AC_BasePickup
	Base Class:	AActor
	Author(s):	Conor Paterson and Jason Mottershead

	Purpose:	To provide base pickup functionality, which allows the pickup to be interacted with.

*/

/* Header Guard. */
#pragma once

#include "MovingObject.h"
#include "C_BasePickup.generated.h"

UCLASS()
class AMAZABALLZ_API AC_BasePickup : public AMovingObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AC_BasePickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
protected:
	// Methods.
	// Collision checks.
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	// Provides standard collision responses for pickups (removing from the scene.)
	void StandardCollisionResponse(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector HitLocation, FVector NormalImpulse, const FHitResult& Hit);
	
	//UFUNCTION()
	// Pure virtual function.
	// Inheriting pickups must provide unique pickup response.
	// Provides unique collision responses for the pickup.
	virtual void UniqueCollisionResponse(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector HitLocation, FVector NormalImpulse, const FHitResult& Hit)
	PURE_VIRTUAL(AC_BasePickup::UniqueCollisionResponse(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector HitLocation, FVector NormalImpulse, const FHitResult& Hit), ;);

};
