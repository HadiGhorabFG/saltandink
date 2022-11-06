#include "GPShotgunLargerInk.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UShotgunLargerInk::ApplySkill(UGPGameInstance* GI)
{
	GI->ShotgunBuffs.activeHealth += ActiveHealth;
}
