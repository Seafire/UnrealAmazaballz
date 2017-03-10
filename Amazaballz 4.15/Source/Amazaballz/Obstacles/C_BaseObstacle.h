// Hilltown Games (C).

/*
 * Base Obstacle
 * =============
 *
 * Created:		2017/03/04 19:45
 * Class Name:	AC_BaseObstacle
 * Base Class:	AActor
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides a base class for setting up many obstacles.
 */

#pragma once

#include <vector>
#include "GameFramework/Actor.h"
#include "Characters/C_Player.h"
#include "C_BaseObstacle.generated.h"

UCLASS(abstract)
class AMAZABALLZ_API AC_BaseObstacle : public AActor
{
	GENERATED_BODY()
	
	public:	
		AC_BaseObstacle();
		virtual ~AC_BaseObstacle();
		virtual void BeginPlay() override;
		virtual void Tick( float DeltaSeconds ) override;

	protected:
		const FName player_tag_;
		APlayerController* player_controller_ = nullptr;
		UStaticMeshComponent* mesh_ = nullptr;
		bool entered_;
		std::vector<AC_Player*> interacting_players_;

		UPROPERTY(EditAnywhere, Category = "Obstacle Properties")	// If this obstacle will be destroyed after a player interacts with it.
			bool destroyed_after_use_;							

		UFUNCTION(BlueprintCallable, Category = "Obstacles")
			virtual void ObstacleResponse(AActor* actor) PURE_VIRTUAL(AC_BaseObstacle::ObstacleResponse(AActor* actor), );

		UFUNCTION(BlueprintCallable, Category = "Obstacles")
			virtual void ObstacleLeft(AActor* actor) PURE_VIRTUAL(AC_BaseObstacle::ObstacleLeft(AActor* actor), );
	
};
