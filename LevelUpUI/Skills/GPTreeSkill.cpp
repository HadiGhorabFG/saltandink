#include "GPTreeSkill.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"
#include "Kismet/GameplayStatics.h"

UGPTreeSkill::UGPTreeSkill()
{
	//GameInstance = UGPGameInstance::Get(this);
}

void UGPTreeSkill::ApplySkill(UGPGameInstance* GI)
{
	UE_LOG(LogTemp, Warning, TEXT("Applying Skill"));
}
