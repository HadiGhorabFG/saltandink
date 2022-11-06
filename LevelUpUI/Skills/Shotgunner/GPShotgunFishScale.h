#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPShotgunFishScale.generated.h"

UCLASS()
class UShotgunFishScale : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float Health;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};
