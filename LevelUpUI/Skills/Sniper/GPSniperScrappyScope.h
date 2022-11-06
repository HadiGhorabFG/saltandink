#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPSniperScrappyScope.generated.h"

UCLASS()
class UGSniperScrappyScope : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float GunRange;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};