// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_Ball.h"

// Sets default values
AC_Ball::AC_Ball()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AC_Ball::BeginPlay()
{
	Super::BeginPlay();
	spawn_position_ = Super::GetActorLocation();
}

/*
 * Resets the position of the ball.
 */
void AC_Ball::Respawn()
{
	Super::SetActorLocation(spawn_position_);
}

// Called every frame
void AC_Ball::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
