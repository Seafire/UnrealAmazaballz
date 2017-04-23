// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_PowerComponent.h"

UC_PowerComponent::UC_PowerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

}

void UC_PowerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UC_PowerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//
	// Set the maximum power boolean depending on the current power levels.
	//
	at_maximum_ = (power_ >= maximum_power_);
}

void UC_PowerComponent::SetPower(float new_power)
{
	power_ = new_power;
}

void UC_PowerComponent::IncreasePower(float increment)
{
	power_ += increment;
}

float UC_PowerComponent::GetPower()
{
	return power_;
}

float UC_PowerComponent::GetMaxPower()
{
	return maximum_power_;
}

bool UC_PowerComponent::IsAtMax()
{
	return at_maximum_;
}