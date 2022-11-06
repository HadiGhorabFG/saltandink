#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPShotgunLargerInk.generated.h"

UCLASS()
class UShotgunLargerInk : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float ActiveHealth;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};
