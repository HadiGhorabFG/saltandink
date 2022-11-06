#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPMachineSupressingShots.generated.h"

UCLASS()
class UMachineSupressingShots : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float AccuracyPen;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};