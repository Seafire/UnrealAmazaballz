// Hilltown Games (C).

/*
 * Player
 * ======
 *
 * Created:		2017/02/19 11:27
 * Class Name:	AC_Player
 * Base Class:	ACharacter
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Provides a standard for any player character in the game.
 */

#pragma once

#include "GameFramework/Character.h"
#include "C_Player.generated.h"

UCLASS()
class AMAZABALLZ_API AC_Player : public ACharacter
{
	GENERATED_BODY()

	public:
		AC_Player();

	protected:
		virtual void BeginPlay() override;

	public:	
		virtual void Tick(float DeltaTime) override;
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

		UFUNCTION(BlueprintCallable, Category = "Player")
			virtual void Movement(float axis_value, bool is_right);

		UFUNCTION(BlueprintCallable, Category = "Player")
			virtual void Jump();

		UFUNCTION(BlueprintCallable, Category = "Player")
			virtual void Respawn();

		UFUNCTION(BlueprintCallable, Category = "Player")
			void SetIsJumping(const bool value);

		UFUNCTION(BlueprintCallable, Category = "Player")
			void SetIndex(const int value);

		UFUNCTION(BlueprintCallable, Category = "Player")
			void SetLives(const int value);

		UFUNCTION(BlueprintCallable, Category = "Player")
			void SetSpawnPosition(const FVector value);

		UFUNCTION(BlueprintCallable, Category = "Player")
			void SetInfiniteLives(const bool value);

		UFUNCTION(BlueprintCallable, Category = "Player")
			int& GetIndex();

		UFUNCTION(BlueprintCallable, Category = "Player")
			int& GetLives();

		UFUNCTION(BlueprintCallable, Category = "Player")
			FVector& GetSpawnPosition();

		UFUNCTION(BlueprintCallable, Category = "Player")
			bool& HasInfiniteLives();

		/*
		 * Provides access to the rolling torque of the player.
		 * @return float the rolling torque value.
		 */
		inline float& get_roll_torque()						{ return roll_torque_; }
		
		/*
		 * Tells us if the player is jumping or not.
		 * @return bool is the player jumping.
		 */
		inline bool& get_is_jumping()						{ return is_jumping_; }
		
		/*
		 * Tells us if the player should respawn or not.
		 * @return bool should this player respawn.
		 */
		inline bool& get_is_spawning()						{ return should_respawn_; }
		
		/*
		 * Tells us if this player can be attacked by other players.
		 * @return bool can this player be attacked.
		 */
		inline bool& get_can_be_attacked()					{ return can_be_attacked_; }
		
		/*
		 * Tells us if the player can use pickups.
		 * @return bool is the player able to use pickups.
		 */
		inline bool& get_can_use_pickups()					{ return can_use_pickups_; }

		/*
		 * Provides a way to set the current spawning flag for the player.
		 * @param value if this player should respawn or not.
		 */
		inline void set_is_spawning(const bool value)		{ should_respawn_ = value; }
		
		/*
		 * Provides a way of making this player invunerable.
		 * @param value if this player can be attacked or not.
		 */
		inline void set_can_be_attacked(const bool value)	{ can_be_attacked_ = value; }
		
		/*
		 * Provides a way of making this player able/unable to use pickups.
		 * @param value if this player can use pickups or not.
		 */
		inline void set_can_use_pickups(const bool value)	{ can_use_pickups_ = value;  }

	protected:
		UPROPERTY(EditAnywhere, Category = "Player Properties")		// How fast will this player move? NOTE: You need to make this value really high apparently.
			float roll_torque_ = 150000000.0f;

		UPROPERTY(EditAnywhere, Category = "Player Properties")		// How much will the player jump up? NOTE: This also needs to be really high.
			float jump_impulse = 400000.0f;

		UPROPERTY(EditAnywhere, Category = "Player Properties")		// What player is this?
			int index_ = 0;

		UPROPERTY(EditAnywhere, Category = "Player Properties")		// Will this player be able to constantly respawn in or not?
			bool has_infinite_lives_ = false;

		UPROPERTY(EditAnywhere, Category = "Player Properties")		// How many lives does this player have?
			int lives_ = 3;

		UStaticMeshComponent* mesh_ = nullptr;
		bool is_jumping_ = false;
		bool can_be_attacked_ = true;
		bool can_use_pickups_ = true;
		bool should_respawn_ = false;
		FVector spawn_position_;

		/*
		 * Provides a way of checking if this player is using physics or not.
		 * @return bool is this player using physics or not.
		 */
		inline bool is_simulating_physics() { return (mesh_->GetBodyInstance()->IsInstanceSimulatingPhysics()); }
};