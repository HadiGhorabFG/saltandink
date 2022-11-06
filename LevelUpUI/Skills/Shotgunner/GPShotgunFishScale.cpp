#include "GPShotgunFishScale.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UShotgunFishScale::ApplySkill(UGPGameInstance* GI)
{
	GI->ShotgunBuffs.health += Health;
}
