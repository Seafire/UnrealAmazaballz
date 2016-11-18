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

	
	
};
