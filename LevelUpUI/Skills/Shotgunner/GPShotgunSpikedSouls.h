#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPShotgunSpikedSouls.generated.h"

UCLASS()
class UShotgunSpikedSouls : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float ActiveSpeed;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};