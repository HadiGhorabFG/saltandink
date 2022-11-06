#include "GPSniperCraniumCrusher.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UGPSniperCraniumCrusher::ApplySkill(UGPGameInstance* GI)
{
	GI->SniperBuffs.activeDamage += Damage;
}
