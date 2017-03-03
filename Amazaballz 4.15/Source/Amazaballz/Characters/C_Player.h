// Hilltown Games (C).

/*
 * Player
 * ======
 *
 * Created:		2017/02/19 11:27:10
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
		// Methods.
		AC_Player();

	protected:
		// Methods.
		virtual void BeginPlay() override;

	public:	
		// Methods.
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
			int& GetIndex();

		UFUNCTION(BlueprintCallable, Category = "Player")
			int& GetLives();

		UFUNCTION(BlueprintCallable, Category = "Player")
			FVector& GetSpawnPosition();

		// Getters/Setters.
		inline float& get_roll_torque() { return roll_torque_; }
		inline bool& get_is_jumping()	{ return is_jumping_; }
		inline bool& get_is_spawning()	{ return should_respawn_; }

		inline void set_is_spawning(const bool value) { should_respawn_ = value; }

	private:
		// Attributes.
		UPROPERTY(EditAnywhere, Category = "Player Properties")		// How fast will this player move? NOTE: You need to make this value really high apparently.
			float roll_torque_ = 150000000.0f;

		UPROPERTY(EditAnywhere, Category = "Player Properties")		// How much will the player jump up? NOTE: This also needs to be really high.
			float jump_impulse = 400000.0f;

		UPROPERTY(EditAnywhere, Category = "Player Properties")		// What player is this?
			int index_ = 0;

		UPROPERTY(EditAnywhere, Category = "Player Properties")		// How many lives does this player have?
			int lives_ = 3;

		UStaticMeshComponent* mesh_ = nullptr;
		bool is_jumping_;
		bool should_respawn_;
		FVector spawn_position_;

		// Getters/Setters.
		// This will allow us to check if the player is simulating physics or not.
		inline bool is_simulating_physics() { return (mesh_->GetBodyInstance()->IsInstanceSimulatingPhysics()); }
};