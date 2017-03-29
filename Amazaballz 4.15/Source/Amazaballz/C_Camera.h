// Hilltown Games (C).

/*
 * Camera
 * ======
 *
 * Created: 	2017/03/04 19:45
 * Class Name: 	AC_Camera
 * Base Class: 	ACameraActor
 * Author(s): 	Jason and Conor
 *
 * Purpose:		This will allow us to provide camera functionality later
 *				in development.
 */

#pragma once

#include "Camera/CameraActor.h"
#include "C_Camera.generated.h"

/**
 * An enum to define what type of camera this is.
 */
UENUM(BlueprintType)
namespace E_CameraType
{
	enum Type
	{
		CT_FIXED			UMETA(DisplayName = "Fixed Camera"),
		CT_AUTO_SCROLL		UMETA(DisplayName = "Auto Scrolling Camera"),
		CT_SCROLL_TARGET	UMETA(DisplayName = "Target Scrolling Camera")
	};
}

/**
 * Provides standard functionality for the game camera.
 */
UCLASS()
class AMAZABALLZ_API AC_Camera : public ACameraActor
{
	GENERATED_BODY()
	
	public:
		/**
		 * Called every frame.
		 * @param DeltaSeconds the time passed since the last frame update.
		 */
		virtual void Tick(float DeltaSeconds) override;

	protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Properties")		// What type of camera is this?
			TEnumAsByte<E_CameraType::Type> camera_type_;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Properties")		// What is the target for this camera?
			AActor* target_;
};