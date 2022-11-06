#include "GPGameInstance.h"
#include "UserInterface/LevelUpUI/GPLevelUpOverlayWidget.h"

void UGPGameInstance::Init()
{
	Super::Init();
	SkillTreeStats.SetNum(UGPLevelUpOverlayWidget::UnitCount);
}

