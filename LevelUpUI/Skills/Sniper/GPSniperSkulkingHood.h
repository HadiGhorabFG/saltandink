#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPSniperSkulkingHood.generated.h"

UCLASS()
class UGPSniperSkulkingHood : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float EvasionInCover;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};