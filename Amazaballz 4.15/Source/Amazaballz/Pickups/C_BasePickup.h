// Hilltown Games (C).

/*
 *	Base Pickup
 *	===========
 *
 * Created:		2017/02/12 20:58
 * Class Name: 	AC_BasePickup
 * Base Class:	AActor
 * Author(s):	Jason Mottershead
 *
 * Purpose:		To provide a standard interface for all pickups in the game, all pickups
 *				must implement logic based on what the base pickup defines.
 *
 */

#pragma once

#include "GameFramework/Actor.h"
#include <iostream>
#include <vector>
#include "Characters/C_Character.h"
#include "C_BasePickup.generated.h"

using namespace std;

/*
 * An enum to define who the pickups effect.
 */
UENUM(BlueprintType)
namespace E_AffectedCharacters
{
	enum Type
	{
		AF_INTERACTING_PLAYER			UMETA(DisplayName = "Interacting Player"),
		AF_ALL_PLAYERS					UMETA(DisplayName = "All Players"),
		AF_ALL_NON_INTERACTING_PLAYERS	UMETA(DisplayName = "All Non Interacting Players"),
		AF_ALLY_TEAM					UMETA(DisplayName = "Ally Players"),
		AF_ENEMY_TEAM					UMETA(DisplayName = "Enemy Players"),
		AF_ALL_ENEMY_CHARACTERS			UMETA(DisplayName = "All Enemy Characters")
	};
}

UCLASS(abstract)
class AMAZABALLZ_API AC_BasePickup : public AActor
{
	GENERATED_BODY()
	
public:	
	AC_BasePickup();
	virtual ~AC_BasePickup();
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

protected:
	const FName player_tag_;
	APlayerController* player_controller_;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup Properties")		// Who will be affected by this pickup?
		TEnumAsByte<E_AffectedCharacters::Type> affected_characters_;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pickup Properties")		// Will the pickup be destroyed after the first use?
		bool destroyed_after_use_ = true;							

	UFUNCTION(BlueprintCallable, Category = "Pickups")
		virtual void PickupResponse(AActor* actor) PURE_VIRTUAL(AC_BasePickup::PickupResponse(AActor* actor), );

	UFUNCTION(BlueprintCallable, Category = "Pickups")
		virtual void PickupDestroy() PURE_VIRTUAL(AC_BasePickup::PickupDestroy(), );

};