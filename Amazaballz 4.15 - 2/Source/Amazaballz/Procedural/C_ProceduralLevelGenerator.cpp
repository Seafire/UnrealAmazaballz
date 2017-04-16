// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_ProceduralLevelGenerator.h"

AC_ProceduralLevelGenerator::AC_ProceduralLevelGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AC_ProceduralLevelGenerator::BeginPlay()
{
	Super::BeginPlay();
}

void AC_ProceduralLevelGenerator::ClearChunks()
{
	if (procedural_chunks_.Num() < 1)
		return;

	procedural_chunks_.Empty();
}

void AC_ProceduralLevelGenerator::AddChunkForClass(ULevelStreaming* chunk)
{
	procedural_chunks_.Add(chunk);
}

TArray<ULevelStreaming*> AC_ProceduralLevelGenerator::GetProceduralChunks()
{
	return procedural_chunks_;
}

void AC_ProceduralLevelGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}