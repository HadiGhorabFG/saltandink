#pragma once
#include "Blueprint/UserWidget.h"
#include "GPLevelUpOverlayWidget.generated.h"

class UGPPlayerUnitStats;
class UCanvasPanel;
class UHorizontalBox;
class UButton;
class UGPLevelUpStatusWidget;
class UGPSkillTreeAssetData;

UCLASS()
class UGPLevelUpOverlayWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	static const int UnitCount = 3;
	
	virtual void NativeConstruct() override;
	void AddUnitStatus(int index);

	UFUNCTION(BlueprintImplementableEvent)
	UCanvasPanel* GetMainCanvas();
	
	UFUNCTION(BlueprintImplementableEvent)
	UHorizontalBox* GetMainHorizontalBox();

	UPROPERTY(EditAnywhere, Category=LevelUpOverlay)
	TSubclassOf<UGPLevelUpStatusWidget> UnitWidgetClass;

	UPROPERTY(EditAnywhere, Category=LevelUpOverlay)
	TArray<UGPSkillTreeAssetData*> TreeDataAssets;
	
	UPROPERTY(BlueprintReadOnly)
	TArray<UGPLevelUpStatusWidget*> LevelUpStatuses;
};
