// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "C_BaseObstacle.generated.h"

UCLASS(abstract)
class AMAZABALLZ_API AC_BaseObstacle : public AActor
{
	GENERATED_BODY()
	
	public:	
		// Sets default values for this actor's properties
		AC_BaseObstacle();
		virtual ~AC_BaseObstacle();

		// Called when the game starts or when spawned
		virtual void BeginPlay() override;
	
		// Called every frame
		virtual void Tick( float DeltaSeconds ) override;

	protected:
		// Attributes.
		const FName player_tag_;
		APlayerController* player_controller_ = nullptr;
		UStaticMeshComponent* mesh_ = nullptr;
		bool entered_;

		// Methods.
		UPROPERTY(EditAnywhere, Category = "Obstacle Properties")	// If this obstacle will be destroyed after a player interacts with it.
			bool destroyed_after_use_;							

		UFUNCTION(BlueprintCallable, Category = "Obstacles")
			virtual void ObstacleResponse(AActor* actor) PURE_VIRTUAL(AC_BaseObstacle::ObstacleResponse(AActor* actor), );

		UFUNCTION(BlueprintCallable, Category = "Obstacles")
			virtual void ObstacleLeft() PURE_VIRTUAL(AC_BaseObstacle::ObstacleLeft(), );
	
};
