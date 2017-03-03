// Hilltown Games (C).

#pragma once

#include "GameFramework/Actor.h"
#include <memory>
#include "Characters/C_Player.h"
#include "Game Modes/C_Ball.h"
#include "C_Net.generated.h"

UENUM(BlueprintType)
namespace E_Team
{
	enum Type
	{
		T_TEAM1			UMETA(DisplayName = "Team One"),
		T_TEAM2			UMETA(DisplayName = "Team Two")
	};
}

UCLASS()
class AMAZABALLZ_API AC_Net : public AActor
{
	GENERATED_BODY()
	
	public:	
		// Sets default values for this actor's properties
		AC_Net();

	protected:
		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	public:
		UFUNCTION(BlueprintCallable, Category = "Ball Game Mode")
			virtual void NetResponse(AActor* actor);

		UFUNCTION(BlueprintCallable, Category = "Ball Game Mode")
			TEnumAsByte<E_Team::Type>& GetTeam();

		// Called every frame
		virtual void Tick(float DeltaTime) override;	

	protected: 
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Net Properties")		// What team this net belongs to.
			TEnumAsByte<E_Team::Type> team_;

	private:
		const FName ball_tag_;
		const FName player_tag_;

};