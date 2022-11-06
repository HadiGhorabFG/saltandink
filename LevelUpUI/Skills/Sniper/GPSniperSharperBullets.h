#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPSniperSharperBullets.generated.h"

UCLASS()
class UGSniperSharperBullets : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float CritChance;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};