#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPShotgunSawedOfBarrel.generated.h"

UCLASS()
class UShotgunSawedOfBarrel : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float GunSpread;
	UPROPERTY(EditAnywhere)
	float Damage;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};