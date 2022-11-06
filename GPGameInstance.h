#pragma once
#include "GPGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FShotgunBuffs
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float health = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float damage = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float gunSpread = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float gunRange = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float rateOfFire = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float activeSpeed = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float activeHealth = 0;
};
	
USTRUCT(BlueprintType)
struct FSniperBuffs
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float gunRange = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float critChance = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float activeDamage = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float evasionPenOnBehindCover = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float evasionBehindCover = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float activeRange = 0;
};
	
USTRUCT(BlueprintType)
struct FMachineBuffs
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float clipSize = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float accuracy = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float activeAOE = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float activeCooldown = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float accuracyPenetration = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float damageOnLowHealth = 0;
};

USTRUCT()
struct FTree
{
	GENERATED_BODY()
	
	int Level = 1;
	int MaxLevel = 3;
	int Points = 0;
	TArray<int> UnlockedSkills;
};

UCLASS()
class UGPGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
	
	UFUNCTION(BlueprintCallable)
	float GetMaxHealth() {return  maxHealth;};
	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(float value) {maxHealth = value;};
	UFUNCTION(BlueprintCallable)
	float GetStartHealth() {return startHealth;};
	UFUNCTION(BlueprintCallable)
	void SetStartHealth(float value) {startHealth = value;};

	UPROPERTY(BlueprintReadWrite)
	FShotgunBuffs ShotgunBuffs;
	UPROPERTY(BlueprintReadWrite)
	FSniperBuffs SniperBuffs;
	UPROPERTY(BlueprintReadWrite)
	FMachineBuffs MachineBuffs;
	FTree Tree;

	UPROPERTY()
	TArray<FTree> SkillTreeStats;

	UPROPERTY(BlueprintReadOnly)
	TArray<APawn*> EnemyUnits;

	UPROPERTY(BlueprintReadOnly)
	TArray<ACharacter*> PlayerUnits;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	AActor* CaravanRef = nullptr;

private:
	float startHealth = 1000.f;
	float maxHealth = 1000.f;
};
