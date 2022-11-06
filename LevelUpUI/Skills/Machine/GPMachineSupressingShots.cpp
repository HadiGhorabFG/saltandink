#include "GPMachineSupressingShots.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UMachineSupressingShots::ApplySkill(UGPGameInstance* GI)
{
	GI->MachineBuffs.accuracyPenetration += AccuracyPen;
}