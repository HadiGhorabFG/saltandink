#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPSniperSpyBinoculars.generated.h"

UCLASS()
class UGSniperSpyBinoculars : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float EvasionPenetrationOnBehindCover;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};	