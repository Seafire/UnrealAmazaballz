// Hilltown Games (C).

#pragma once

#include "GameFramework/Character.h"
#include "C_Character.generated.h"

UCLASS()
class AMAZABALLZ_API AC_Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;
public:
	AC_Character();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	/**
	 * Provides a way for this character to attack.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		virtual void Attack();

	/**
	 * Stops attacking.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		virtual void StopAttack();

	/**
	 * Provides a way for this character to attack.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		virtual void Defend();

	/**
	 * Stops attacking.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		virtual void StopDefend();

	/**
	 * Provides a way for this character to respawn.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		virtual void Respawn();

	/**
	 * Allows us to set the spawning status of this player.
	 * @param value if this player should spawn in or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetSpawningStatus(const bool value);

	/**
	 * Allows us to disable attacks on this player.
	 * @param value if this player can be attacked.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetCanBeAttacked(const bool value);

	/**
	 * Allows us to disable pickups for this player.
	 * @param value if this player can use pickups or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetCanUsePickups(const bool value);

	/**
	 * Allows us to set the current player index value for this character.
	 * @param index the index number of this player.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetIndex(const int32 index);

	/**
	 * Allows us to make this player immortal.
	 * @param value if this player has infinite lives or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetInfiniteLives(const bool value);

	/**
	 * Sets the current attack state.
	 * @param value if this player is attacking or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetAttackState(const bool value);

	/**
	 * Allows us to alter the speed of this character.
	 * @param speedMultiplier how fast this player should move.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetSpeed(const float speedMultiplier);

	/**
	 * Allows us to reset the speed modifier for this character to the original value.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetSpeedToNormal();

	/**
	 * Allows us to set the current amount of lives this player has.
	 * @param lives how many lives to add onto this player.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetLives(int lives);

	/**
	 * Sets the spawn location for this character.
	 * @param value where the spawn location is.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetSpawnPosition(const FVector value);

	/**
	 * Provides access to the current spawning status of this character.
	 * @return bool& if this player should respawn or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		bool& IsSpawning();

	/**
	 * Provides access to the current invincibility status of the player.
	 * @return bool& if this player has can be attacked by other players or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		bool& CanBeAttacked();

	/**
	 * Provides access to the current pickup status of this player.
	 * @return bool& if this player can use pickups or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		bool& CanUsePickups();

	/**
	 * Provides access to the current player index for this character.
	 * @return int the index number for this player.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		int32& GetIndex();

	/**
	 * Provides access to the current status for infinite lives for this player.
	 * @return bool& if this player has infinite lives or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		bool& HasInfiniteLives();

	/**
	 * Provides access to the attack status of the player.
	 * @return bool& if this player is attacking or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		bool& IsAttacking();

	/**
	 * Provides access to the current speed modifier for this character.
	 * @return float& the value of the speed modifier for this character.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		float& GetSpeed();

	/**
	 * Provides access to the current number of lives this player has.
	 * @return int the number of lives for this player.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		int& GetLives();

protected:
	bool is_spawning_ = false;
	bool can_be_attacked_ = true, can_use_pickups_ = true;
	bool is_attacking_ = false;
	float original_speed_ = 1.0f;
	float speed_ = 1.0f;
	FVector spawn_position_;
	AActor* current_target_;

	UPROPERTY(EditAnywhere, Category = "Player Properties")		// How many lives does this player have?
		int32 player_index_ = -1;

	UPROPERTY(EditAnywhere, Category = "Player Properties")		// Will this player be able to constantly respawn in or not?
		bool has_infinite_lives_ = false;

	UPROPERTY(EditAnywhere, Category = "Player Properties")		// How many lives does this player have?
		int lives_ = 3;

	UPROPERTY(EditAnywhere, Category = "Player Properties")		// How much force does each attack have?
		float attack_force_ = 1000.0f;

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

	float ray_distance_ = 100.0f;

	/**
	 * Performs a raycast from this character.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void Raycast();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
};
