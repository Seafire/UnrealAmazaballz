// Hilltown Games (C).

#include "Amazaballz.h"
#include "C_OrbOfPowerPickup.h"

//AC_OrbOfPowerPickup::AC_OrbOfPowerPickup()
//{
//	particle_system_ = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle System Component"));
//}

void AC_OrbOfPowerPickup::PickupResponse(AActor* actor)
{
	// Accessing the static mesh component of the character and checking if the actor is a player character.
	bool is_player = actor->ActorHasTag(player_tag_);

	// If this actor is a player character.
	if (is_player)
	{
		AC_Character* player = Cast<AC_Character>(actor);
		UC_PowerComponent* power_component = player->FindComponentByClass<UC_PowerComponent>();
		pickup_mesh_ = FindComponentByClass<UStaticMeshComponent>();

		if (!picked_up_ && player->CanUsePickups())
		{
			if (power_component)
			{
				if (!power_component->IsAtMax())
					power_component->IncreasePower(amount_of_power_);
			}

			picked_up_ = true;
			PickupDestroy();
		}
	}
}

void AC_OrbOfPowerPickup::PickupDestroy()
{
	// Destroy the pickup.
	pickup_mesh_->SetVisibility(false);
	pickup_mesh_->DestroyComponent();
}

void AC_OrbOfPowerPickup::ApplyPickupEffect()
{}

void AC_OrbOfPowerPickup::UndoPickupEffect()
{}