// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "C_BasePickup.h"

// Sets default values
AC_BasePickup::AC_BasePickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

AC_BasePickup::~AC_BasePickup()
{
	// Delete any pointers here...
}

// Called when the game starts or when spawned
void AC_BasePickup::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AC_BasePickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}