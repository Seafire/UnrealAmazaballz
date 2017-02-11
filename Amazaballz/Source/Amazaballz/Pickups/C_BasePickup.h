// Fill out your copyright notice in the Description page of Project Settings.

/*

	Base Pickup
	===========

	Created:	2017/02/12 20:58:10
	Class Name: AC_BasePickup
	Base Class:	AActor
	Author(s):	Jason Mottershead

	Purpose:	To provide a standard interface for all pickups in the game, all pickups
				must implement logic based on what the base pickup defines.

*/

// Header guard.
#pragma once

// Includes here.
#include <iostream>
#include "GameFramework/Actor.h"
#include "C_BasePickup.generated.h"

using namespace std;

UCLASS(abstract)
class AMAZABALLZ_API AC_BasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AC_BasePickup();
	virtual ~AC_BasePickup();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

protected:
	UFUNCTION(BlueprintCallable, Category = "Pickups")
		virtual void PickupResponse(AActor* actor) PURE_VIRTUAL(AC_BasePickup::PickupResponse(AActor* actor), );

	UFUNCTION(BlueprintCallable, Category = "Pickups")
		virtual void PickupDestroy() PURE_VIRTUAL(AC_BasePickup::PickupDestroy(), );
	
};
