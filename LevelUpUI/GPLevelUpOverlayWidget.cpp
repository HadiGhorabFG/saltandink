#include "GPLevelUpOverlayWidget.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/HorizontalBox.h"
#include "Components/Button.h"
#include "GPLevelUpStatusWidget.h"

void UGPLevelUpOverlayWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	for (int i = 0; i < UnitCount; i++)
	{
		AddUnitStatus(i);
	}
}

void UGPLevelUpOverlayWidget::AddUnitStatus(int index)
{
	UGPLevelUpStatusWidget* unitStatus = NewObject<UGPLevelUpStatusWidget>(this, UnitWidgetClass);
	unitStatus->Index = index;
	unitStatus->SkillTree = TreeDataAssets[index];
	unitStatus->SetPadding(FMargin(8, 30, 8, 0));

	LevelUpStatuses.Add(unitStatus);
	GetMainHorizontalBox()->AddChildToHorizontalBox(unitStatus);
}
