#include "GPMachineUnderdogPills.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UMachineUnderdogPills::ApplySkill(UGPGameInstance* GI)
{
	GI->MachineBuffs.damageOnLowHealth += Damage;
}
