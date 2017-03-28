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
	 * Allows us to set the current player index value for this character.
	 * @param index the index number of this player.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetIndex(int index);

	/**
	 * Allows us to make this player immortal.
	 * @param value if this player has infinite lives or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		void SetInfiniteLives(const bool value);

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
	 * Provides access to the current player index for this character.
	 * @return int the index number for this player.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		int GetIndex();

	/**
	 * Provides access to the current status for infinite lives for this player.
	 * @return bool& if this player has infinite lives or not.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		bool& HasInfiniteLives();

	/**
	 * Provides access to the current speed modifier for this character.
	 * @return float& the value of the speed modifier for this character.
	 */
	UFUNCTION(BlueprintCallable, Category = "Player")
		float& GetSpeed();

protected:
	int player_index_ = 0;
	float original_speed_ = 1.0f;
	float speed_ = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Player Properties")		// Will this player be able to constantly respawn in or not?
		bool has_infinite_lives_ = false;

	UPROPERTY(EditAnywhere, Category = "Player Properties")		// How many lives does this player have?
		int lives_ = 3;

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

	

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
};
