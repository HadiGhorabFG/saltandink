#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPMachinePackedGrenades.generated.h"

UCLASS()
class UMachinePackedGrenades : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float ActiveAOE;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};
