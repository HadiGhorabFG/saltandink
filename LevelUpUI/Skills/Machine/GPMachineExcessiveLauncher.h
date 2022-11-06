#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPMachineExcessiveLauncher.generated.h"

UCLASS()
class UMachineExcessiveLauncher : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float ActiveCooldown;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};
