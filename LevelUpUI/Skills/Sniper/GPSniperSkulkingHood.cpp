#include "GPSniperSkulkingHood.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UGPSniperSkulkingHood::ApplySkill(UGPGameInstance* GI)
{
	GI->SniperBuffs.evasionBehindCover += EvasionInCover;
}