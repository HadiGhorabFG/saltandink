#include "GPSniperScrappyScope.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UGSniperScrappyScope::ApplySkill(UGPGameInstance* GI)
{
	GI->SniperBuffs.gunRange += GunRange;
}