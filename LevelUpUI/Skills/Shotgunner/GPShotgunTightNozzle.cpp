#include "GPShotgunTightNozzle.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UShotgunTightNozzle::ApplySkill(UGPGameInstance* GI)
{
	GI->ShotgunBuffs.gunRange += GunRange;
	
	GI->ShotgunBuffs.gunSpread -= GunSpread;
}