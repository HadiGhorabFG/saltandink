#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPShotgunGreasedTrigger.generated.h"

UCLASS()
class UShotgunGreasedTrigger : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float RateOfFire;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};
