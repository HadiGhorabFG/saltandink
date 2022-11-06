#include "GPMachinePackedGrenades.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UMachinePackedGrenades::ApplySkill(UGPGameInstance* GI)
{
	GI->MachineBuffs.activeAOE += ActiveAOE;
}
