// Hilltown Games (C).

/*
 * Ball
 * ====
 *
 * Created:		2017/03/04 19:45
 * Class Name:	AC_Ball
 * Base Class:	AActor
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides standard functionality for the ball in a game mode.
 */

#pragma once

#include "GameFramework/Actor.h"
#include "C_Ball.generated.h"

UCLASS()
class AMAZABALLZ_API AC_Ball : public AActor
{
	GENERATED_BODY()
	
	public:	
		AC_Ball();

	protected:
		virtual void BeginPlay() override;

	public:	
		UFUNCTION(BlueprintCallable, Category = "Ball Game Mode")
			virtual void Respawn();

		virtual void Tick(float DeltaTime) override;

	protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ball Properties")		// What team this net belongs to.
			AActor* spawn_point_;

	private:
		FVector spawn_position_;
		UStaticMeshComponent* mesh_;
};
