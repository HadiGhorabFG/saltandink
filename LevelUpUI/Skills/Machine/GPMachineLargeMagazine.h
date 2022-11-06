#pragma once
#include "GP3_Team11_Caravan/UserInterface/LevelUpUI/Skills/GPTreeSkill.h"
#include "GPMachineLargeMagazine.generated.h"

UCLASS()
class UMachineLargeMagazine : public UGPTreeSkill
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float ClipSize;
	
	virtual void ApplySkill(UGPGameInstance* GI) override;
};