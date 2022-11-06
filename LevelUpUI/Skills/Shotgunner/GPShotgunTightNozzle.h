#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPShotgunTightNozzle.generated.h"

UCLASS()
class UShotgunTightNozzle : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float GunSpread;
	UPROPERTY(EditAnywhere)
	float GunRange;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};