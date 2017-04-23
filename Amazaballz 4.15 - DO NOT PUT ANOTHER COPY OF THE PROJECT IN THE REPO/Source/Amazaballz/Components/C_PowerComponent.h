// Hilltown Games (C).

/**
 * Power Component
 * ===============
 *
 * Created:		2017/04/22 22:16
 * Class Name:	UC_PowerComponent
 * Base Class:	UActorComponent
 * Author(s):	Jason Mottershead
 *
 * Purpose:		Any actor can now store power.
 */

#pragma once

#include "Components/ActorComponent.h"
#include "C_PowerComponent.generated.h"

/**
 * Any actor can now store power.
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class AMAZABALLZ_API UC_PowerComponent : public UActorComponent
{
	GENERATED_BODY()

	public:	
		/**
		 * Sets the default values.
		 */
		UC_PowerComponent();

	protected:
		/**
		 * Called when the game starts or when spawned.
		 */
		virtual void BeginPlay() override;

	public:	
		/**
		 * Called every frame.
		 * @param DeltaTime the time passed since the last frame update.
		 * @param TickType what type of update this component uses, i.e. if we are paused, or running in the editor.
		 * @param ThisTickFunction internal tick function struct that cause this to run.
		 */
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
		/**
		 * Provides a way to set the current power level.
		 */
		UFUNCTION(BlueprintCallable, Category = "Power Component")
			void SetPower(float new_power);

		/**
		 * Provides a way to increase the current power level by a specific amount.
		 */
		UFUNCTION(BlueprintCallable, Category = "Power Component")
			void IncreasePower(float increment);

		/**
		 * Provides a way to get the current power level.
		 */
		UFUNCTION(BlueprintCallable, Category = "Power Component")
			float GetPower();

		/**
		 * Provides a way to get the maximum power level.
		 */
		UFUNCTION(BlueprintCallable, Category = "Power Component")
			float GetMaxPower();

		/**
		 * Provides a way to see if this power component is at the maximum power level.
		 */
		UFUNCTION(BlueprintCallable, Category = "Power Component")
			bool IsAtMax();

	protected:
		UPROPERTY(EditAnywhere, Category = "Power Component")		// What amount should the power level start at?
			float power_ = 0.0f;

		UPROPERTY(EditAnywhere, Category = "Power Component")		// What is the maximum power level?
			float maximum_power_ = 0.0f;

		bool at_maximum_ = false;									// Is this power component at the maximum power level?
};