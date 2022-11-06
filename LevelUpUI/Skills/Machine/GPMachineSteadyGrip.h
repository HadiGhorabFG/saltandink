#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPMachineSteadyGrip.generated.h"

UCLASS()
class UMachineSteadyGrip : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float Accuracy;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};