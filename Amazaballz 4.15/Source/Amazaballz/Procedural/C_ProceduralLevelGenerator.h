// Hilltown Games (C).

#pragma once

#include "GameFramework/Actor.h"
#include "Engine/LevelStreaming.h"
#include "C_ProceduralLevelGenerator.generated.h"

/**
 * Provides a way to procedurally generate levels.
 */
UCLASS()
class AMAZABALLZ_API AC_ProceduralLevelGenerator : public AActor
{
	GENERATED_BODY()
	
	public:	
		/**
		 * Sets the default values.
		 */
		AC_ProceduralLevelGenerator();

	protected:
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Map Properties")		// How many chunks along the x axis?
			int map_size_x_ = 10;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Map Properties")		// How many chunks along the y axis?
			int map_size_y_ = 10;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Chunks")				// How wide can chunks be?
			float chunk_size_x_ = 10.0f;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Chunks")				// How long can chunks be?
			float chunk_size_y_ = 10.0f;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Chunks")				// Should each chunk randomly rotate itself?
			bool random_rotation_ = false;

		TArray<ULevelStreaming*> procedural_chunks_;

		/**
		 * Called when the game starts or when spawned.
		 */
		virtual void BeginPlay() override;

		/**
		 * Clears all of the current procedural chunk references.
		 */
		UFUNCTION(BlueprintCallable, Category = "Procedural")
			void ClearChunks();

		/**
		 * Adds a procedural level into our C++ reference.
		 */
		UFUNCTION(BlueprintCallable, Category = "Procedural")
			void AddChunkForClass(ULevelStreaming* chunk);
		
		/**
		 * Provides access to our randomly generated level chunks.
		 * @return TArray<ULevelStreaming*> the array of level chunks.
		 */
		UFUNCTION(BlueprintCallable, Category = "Procedural")
			TArray<ULevelStreaming*> GetProceduralChunks();

	public:	
		/**
		 * Called every frame.
		 * @param DeltaTime the time passed since the last frame update.
		 */
		virtual void Tick(float DeltaTime) override;

};