#pragma once
#include "GPSkillTreeAssetData.generated.h"

class UGPTreeSkill;

USTRUCT(BlueprintType)
struct FSkill
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGPTreeSkill> Class;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* Icon;
};

UCLASS(BlueprintType)
class UGPSkillTreeAssetData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D* UnitIcon;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName UnitName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName UnitTitle;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString UnitBorderColorHex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FSkill> Skills;
};
