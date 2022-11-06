#include "GPSniperSpyBinoculars.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UGSniperSpyBinoculars::ApplySkill(UGPGameInstance* GI)
{
	GI->SniperBuffs.evasionPenOnBehindCover += EvasionPenetrationOnBehindCover;
}