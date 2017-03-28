// Hilltown Games (C).

/*
 * Boulder
 * =======
 *
 * Created:		2017/03/28 21:00
 * Class Name:	AC_Boulder
 * Base Class:	AActor
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides standard functionality for the boulder for the boulder 
 *				dash game mode.
 */

#pragma once

#include "GameFramework/Actor.h"
#include "Characters/C_Character.h"
#include "C_Boulder.generated.h"

UCLASS()
class AMAZABALLZ_API AC_Boulder : public AActor
{
	GENERATED_BODY()
	
	public:	
		/**
		 * Sets the default values.
		 */
		AC_Boulder();

	protected:
		/**
		 * Called when the game starts or when spawned.
		 */
		virtual void BeginPlay() override;
		
	protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boulder Properties")		// How much force should be applied to start this boulder rolling?
			FVector starting_force_;

		/**
		 * Provides a response when an actor collides with this boulder.
		 * @param actor the actor that is colliding with this game object.
		 */
		UFUNCTION(BlueprintCallable, Category = "Boulder")
			void BoulderResponse(AActor* actor);

	private:
		UStaticMeshComponent* mesh_;
	
};
