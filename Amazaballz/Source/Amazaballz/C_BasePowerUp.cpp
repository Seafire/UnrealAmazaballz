// Fill out your copyright notice in the Description page of Project Settings.

#include "Amazaballz.h"
#include "C_BasePowerUp.h"


// Sets default values
AC_BasePowerUp::AC_BasePowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AC_BasePowerUp::BeginPlay()
{
	Super::BeginPlay();
	
}

void AC_BasePowerUp::NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	StandardCollisionResponse(Other, OtherComp, HitLocation, NormalImpulse, Hit);
}

void AC_BasePowerUp::StandardCollisionResponse(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector HitLocation, FVector NormalImpulse, const FHitResult& Hit)
{
	// Remove the pickup.


	//UniqueCollisionResponse(OtherActor, OtherComp, HitLocation, NormalImpulse, Hit);
}

// Called every frame
void AC_BasePowerUp::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

