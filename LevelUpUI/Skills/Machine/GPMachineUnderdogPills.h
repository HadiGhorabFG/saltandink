#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPMachineUnderdogPills.generated.h"

UCLASS()
class UMachineUnderdogPills : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float Damage;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};
