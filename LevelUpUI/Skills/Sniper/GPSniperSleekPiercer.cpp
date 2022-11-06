#include "GPSniperSleekPiercer.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UGPSniperSleekPiercer::ApplySkill(UGPGameInstance* GI)
{
	GI->SniperBuffs.activeRange += ActiveRange;
}