// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_Net.h"

/*
 * Sets the default values.
 */
AC_Net::AC_Net() :
	ball_tag_("Ball"),
	player_tag_("Player")
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

/*
 * Called when the game starts or when spawned.
 */
void AC_Net::BeginPlay()
{
	Super::BeginPlay();	
}

/*
 * This will provide a response for what happens when this net is being interacted with.
 * @param actor the actor that is interacting with this net.
 */
void AC_Net::NetResponse(AActor* actor)
{
	// If the actor is a player, respawn them.
	if (actor->ActorHasTag(player_tag_))
	{
		AC_Player* player = Cast<AC_Player>(actor);
		player->set_is_spawning(true);
		player->Respawn();
	}
	
	// If the actor is a ball, score a goal and respawn.
	if(actor->ActorHasTag(ball_tag_))
	{
		AC_Ball* ball = Cast<AC_Ball>(actor);

		if (ball != nullptr)
			ball->Respawn();
	}
}

/*
 * This will provide access to the team that this net belongs to.
 * @return E_Team the team that this belongs to.
 */
TEnumAsByte<E_Team::Type>& AC_Net::GetTeam()
{
	return team_;
}

/*
 * Called every frame.
 * @param DeltaTime the time passed since the last frame update.
 */
void AC_Net::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

