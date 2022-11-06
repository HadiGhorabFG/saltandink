#include "GPShotgunSawedOfBarrel.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UShotgunSawedOfBarrel::ApplySkill(UGPGameInstance* GI)
{
	GI->ShotgunBuffs.gunSpread += GunSpread;
	GI->ShotgunBuffs.damage += Damage;
}