#include "GPMachineExcessiveLauncher.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UMachineExcessiveLauncher::ApplySkill(UGPGameInstance* GI)
{
	GI->MachineBuffs.activeCooldown += ActiveCooldown;
}