// Hilltown Games (C).

/**
 * Projectile
 * ==========
 *
 * Created:		2017/04/24 16:21
 * Class Name:	AC_RandomSpawner
 * Base Class:	AActor
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Randomly spawns an actor at this location.
 */

#pragma once

#include "GameFramework/Actor.h"
#include "C_RandomSpawner.generated.h"

/**
 * Randomly spawns an actor at this location.
 */
UCLASS()
class AMAZABALLZ_API AC_RandomSpawner : public AActor
{
	GENERATED_BODY()
	
	public:	
		/**
		 * Sets the default values.
		 */
		AC_RandomSpawner();

	protected:
		/**
		 * Called when the game starts or when spawned.
		 */
		virtual void BeginPlay() override;

		/**
		 * Spawns a random actor on this location.
		 */
		void ChooseRandomActor();

		/**
		 * Spawns in a new actor based off a template given.
		 * @param template_actor the actor to base this new actor off of.
		 */
		void SpawnActor(AActor* template_actor);

		UPROPERTY(EditAnywhere, Category = "Random Spawner Properties")	// What actors are we allowed to spawn here?
			TArray<TSubclassOf<AActor>> actors_;
};