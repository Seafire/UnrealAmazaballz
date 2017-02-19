// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_BasePickup.h"

// Sets default values
AC_BasePickup::AC_BasePickup() :
	player_tag_("Player"),
	player_controller_(nullptr)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

AC_BasePickup::~AC_BasePickup()
{}

// Called when the game starts or when spawned
void AC_BasePickup::BeginPlay()
{
	Super::BeginPlay();

	/*
	This can be used for C++ debug comments to the editor.
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("mesh velocity X = %f"), linear_velocity.X));
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("mesh velocity Y = %f"), linear_velocity.Y));
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, FString::Printf(TEXT("mesh velocity Z = %f"), linear_velocity.Z));
	}
	*/
}

// Called every frame
void AC_BasePickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}