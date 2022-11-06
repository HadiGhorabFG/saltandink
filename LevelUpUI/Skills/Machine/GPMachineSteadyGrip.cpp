#include "GPMachineSteadyGrip.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UMachineSteadyGrip::ApplySkill(UGPGameInstance* GI)
{
	GI->MachineBuffs.accuracy += Accuracy;
}