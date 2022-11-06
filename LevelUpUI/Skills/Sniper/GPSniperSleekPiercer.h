#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPSniperSleekPiercer.generated.h"

UCLASS()
class UGPSniperSleekPiercer : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float ActiveRange;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};
