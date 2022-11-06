#include "GPSniperSharperBullets.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UGSniperSharperBullets::ApplySkill(UGPGameInstance* GI)
{
	GI->SniperBuffs.critChance += CritChance;
}