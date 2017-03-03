// Hilltown Games (C).

#pragma once

#include "GameFramework/Actor.h"
#include "C_Ball.generated.h"

UCLASS()
class AMAZABALLZ_API AC_Ball : public AActor
{
	GENERATED_BODY()
	
	public:	
		// Sets default values for this actor's properties
		AC_Ball();

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:	
		UFUNCTION(BlueprintCallable, Category = "Ball")
			virtual void Respawn();

		// Called every frame
		virtual void Tick(float DeltaTime) override;

	private:
		FVector spawn_position_;
};
