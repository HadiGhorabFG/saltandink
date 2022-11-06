#pragma once
#include "GPTreeSkill.generated.h"

class UGPGameInstance;

UCLASS(Blueprintable, BlueprintType)
class UGPTreeSkill : public UObject
{
	GENERATED_BODY()
	
public:
	UGPTreeSkill();
	virtual void ApplySkill(UGPGameInstance* GI);
	//virtual void ApplySkill();
};
