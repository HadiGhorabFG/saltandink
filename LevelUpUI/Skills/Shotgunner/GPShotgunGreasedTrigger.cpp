#include "GPShotgunGreasedTrigger.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UShotgunGreasedTrigger::ApplySkill(UGPGameInstance* GI)
{
	GI->ShotgunBuffs.rateOfFire += RateOfFire;
}