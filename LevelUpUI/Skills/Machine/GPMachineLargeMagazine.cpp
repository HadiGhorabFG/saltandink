#include "GPMachineLargeMagazine.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UMachineLargeMagazine::ApplySkill(UGPGameInstance* GI)
{
	GI->MachineBuffs.clipSize += ClipSize;
}