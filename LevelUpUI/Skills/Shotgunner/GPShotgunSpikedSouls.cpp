#include "GPShotgunSpikedSouls.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UShotgunSpikedSouls::ApplySkill(UGPGameInstance* GI)
{
	GI->ShotgunBuffs.activeSpeed += ActiveSpeed;
}