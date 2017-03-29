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
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
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

		/**
		 * Provides a way to push the boulder with a given impulse.
		 * @param force the force to apply to this boulder.
		 */
		UFUNCTION(BlueprintCallable, Category = "Boulder")
			void Push(const FVector force);

		/**
		 * Called every frame.
		 * @param DeltaSeconds the time passed since the last frame.
		 */
		virtual void Tick(float DeltaSeconds) override;

	protected:
		//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boulder Properties")
			int32 number_of_players_;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boulder Properties")		// How much force should be applied to start this boulder rolling?
			FVector starting_force_;	

		/**
		 * Called when the game starts or when spawned.
		 */
		virtual void BeginPlay() override;
		
		/**
		 * Provides a response when an actor collides with this boulder.
		 * @param actor the actor that is colliding with this game object.
		 */
		UFUNCTION(BlueprintCallable, Category = "Boulder")
			void BoulderResponse(AActor* actor);

	private:
		UStaticMeshComponent* mesh_;
	
		/**
		 * Provides a standard response for the player interacting with the boulder.
		 * @param player the player who has made contact with the boulder.
		 */
		void PlayerResponse(AC_Character* player);

		/**
		 * Provides a standard response for the obstacle interacting with the boulder.
		 * @param actor the actor obstacle that has made contact with the boulder.
		 */
		void ObstacleResponse(AActor* actor);
};
