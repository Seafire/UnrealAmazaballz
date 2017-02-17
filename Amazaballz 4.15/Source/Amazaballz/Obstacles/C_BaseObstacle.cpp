// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "C_BaseObstacle.h"

// Sets default values
AC_BaseObstacle::AC_BaseObstacle() :
	player_tag_("Player"),
	player_controller_(nullptr),
	entered_(false)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

AC_BaseObstacle::~AC_BaseObstacle()
{}

// Called when the game starts or when spawned
void AC_BaseObstacle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AC_BaseObstacle::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}