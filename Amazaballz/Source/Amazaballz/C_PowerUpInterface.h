// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "C_PowerUpInterface.generated.h"

/**
 * 
 */
UINTERFACE(BlueprintType)
class AMAZABALLZ_API UC_PowerUpInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class AMAZABALLZ_API IC_PowerUpInterface
{
	GENERATED_IINTERFACE_BODY()

public:
	// Methods.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Power Up Attribute")
		float GetMultiplier();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Power Up Attribute")
		bool GetToggle();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Power Up Attribute")
		void PowerUp(AActor* actor);

};
