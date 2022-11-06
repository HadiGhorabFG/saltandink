#include "GPLevelUpStatusWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Skills/GPSkillTreeAssetData.h"
#include "Skills/GPTreeSkill.h"
#include "Kismet/GameplayStatics.h"
#include "GP3_Team11_Caravan/GPGameInstance.h"

void UGPLevelUpStatusWidget::NativeConstruct()
{
	Super::NativeConstruct();
	GameInstance = GetWorld()->GetGameInstance<UGPGameInstance>();
	
	InitSkillClickEvents();
	InitSkills(GameInstance->SkillTreeStats[Index].Level); // 1-3
	InitHeader();
	
	LockTree(GameInstance->SkillTreeStats[Index].UnlockedSkills);

	GameInstance->SkillTreeStats[Index].Points++;

	bUpdateUI = true;
}

void UGPLevelUpStatusWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if(bUpdateUI)
	{
		GetPointsTextWidget()->SetText(FText::FromString(FString::Printf(TEXT("Points: %d"),
			GameInstance->SkillTreeStats[Index].Points)));

		if(GameInstance->SkillTreeStats[Index].Points > 0)
		{
			GetPointsWarningTextWidget()->SetVisibility(ESlateVisibility::Visible);
		}
		else GetPointsWarningTextWidget()->SetVisibility(ESlateVisibility::Hidden);
		
		bUpdateUI = false;	
	}

	const int level = GameInstance->SkillTreeStats[Index].Level;

	// locks tree if you have no points even tho the option is unlocked
	// TODO: does this have to be in tick?
	for(int i = (level * 2) - 1; i > ((level * 2) - 1) - 2; i--)
	{
		const int points = GameInstance->SkillTreeStats[Index].Points;
		const int maxLevel = GameInstance->SkillTreeStats[Index].MaxLevel;
		
		if(points > 0 && level <= maxLevel)
		{
			GetSkillsButtons()[i]->SetVisibility(ESlateVisibility::Visible);
		}
		else if(level <= maxLevel)
		{
			GetSkillsButtons()[i]->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void UGPLevelUpStatusWidget::LockTree(TArray<int> activeSkills)
{
	for (int skillIndex : activeSkills)
	{
		UnlockSkill(skillIndex, false);
	}
}

void UGPLevelUpStatusWidget::InitHeader()
{
	GetNameTextWidget()->SetText(FText::FromName(SkillTree->UnitName));
	GetTitleTextWidget()->SetText(FText::FromName(SkillTree->UnitTitle));
	GetHeaderBorderImage()->SetColorAndOpacity(FLinearColor(FColor::FromHex(SkillTree->UnitBorderColorHex)));
	GetHeaderIconImage()->SetBrushResourceObject(SkillTree->UnitIcon);

	GetHeaderIconImage()->Brush.ImageSize = FVector2D(SkillTree->UnitIcon->GetImportedSize().X/2,
		SkillTree->UnitIcon->GetImportedSize().Y/2);
}

void UGPLevelUpStatusWidget::InitSkillClickEvents()
{
	GetSkillsButtons()[0]->OnClicked.AddDynamic(this, &UGPLevelUpStatusWidget::OnSkillOnePressed);
	GetSkillsButtons()[1]->OnClicked.AddDynamic(this, &UGPLevelUpStatusWidget::OnSkillTwoPressed);
	GetSkillsButtons()[2]->OnClicked.AddDynamic(this, &UGPLevelUpStatusWidget::OnSkillThreePressed);
	GetSkillsButtons()[3]->OnClicked.AddDynamic(this, &UGPLevelUpStatusWidget::OnSkillFourPressed);
	GetSkillsButtons()[4]->OnClicked.AddDynamic(this, &UGPLevelUpStatusWidget::OnSkillFivePressed);
	GetSkillsButtons()[5]->OnClicked.AddDynamic(this, &UGPLevelUpStatusWidget::OnSkillSixPressed);
}

void UGPLevelUpStatusWidget::InitSkills(int level)
{
	//Initialize every skill from the data asset
	for(int i = 0; i < GetSkillsButtons().Num(); i++)
	{
		GetSkillsButtons()[i]->WidgetStyle.Normal.SetResourceObject(SkillTree->Skills[i].Icon);
		GetSkillsButtons()[i]->WidgetStyle.Hovered.SetResourceObject(SkillTree->Skills[i].Icon);
		GetSkillsButtons()[i]->WidgetStyle.Pressed.SetResourceObject(SkillTree->Skills[i].Icon);
		GetSkillsDisabledImages()[i]->SetBrushResourceObject(SkillTree->Skills[i].Icon);
	}

	UnlockSkillTree(level);
	DisableSkillTree(level);
}

void UGPLevelUpStatusWidget::OnSkillOnePressed()
{
	if(GameInstance->SkillTreeStats[Index].Points > 0)
		UnlockSkill(0, true);
}

void UGPLevelUpStatusWidget::OnSkillTwoPressed()
{
	if(GameInstance->SkillTreeStats[Index].Points > 0)
		UnlockSkill(1, true);
}

void UGPLevelUpStatusWidget::OnSkillThreePressed()
{
	if(GameInstance->SkillTreeStats[Index].Points > 0)
		UnlockSkill(2, true);
}

void UGPLevelUpStatusWidget::OnSkillFourPressed()
{
	if(GameInstance->SkillTreeStats[Index].Points > 0)
		UnlockSkill(3, true);
}

void UGPLevelUpStatusWidget::OnSkillFivePressed()
{
	if(GameInstance->SkillTreeStats[Index].Points > 0)
		UnlockSkill(4, true);
}

void UGPLevelUpStatusWidget::OnSkillSixPressed()
{
	if(GameInstance->SkillTreeStats[Index].Points > 0)
		UnlockSkill(5, true);
}

void UGPLevelUpStatusWidget::UnlockSkill(int skillIndex, bool applySkill)
{
	int level = GameInstance->SkillTreeStats[Index].Level;
	
	if(applySkill && GameInstance->SkillTreeStats[Index].Points >= 1)
	{
		SkillTree->Skills[skillIndex].Class.GetDefaultObject()->ApplySkill(GameInstance);
		GameInstance->SkillTreeStats[Index].UnlockedSkills.Add(skillIndex);
		GameInstance->SkillTreeStats[Index].Points--;
		GameInstance->SkillTreeStats[Index].Level++;

		level = GameInstance->SkillTreeStats[Index].Level;
	}

	UnlockSkillTree(level);
	DisableSkillTree(level);

	bUpdateUI = true;
}

void UGPLevelUpStatusWidget::UnlockSkillTree(int level)
{	
	for(int i = 0; i < GetSkillsButtons().Num(); i++)
	{
		if(GameInstance->SkillTreeStats[Index].UnlockedSkills.Contains(i))
		{
			GetSkillsDisabledImages()[i]->SetBrushTintColor(UnlockedTint);
			GetSkillsDisabledImages()[i]->Brush.OutlineSettings.Color = UnlockedBorderColor;
		}
		else
		{
			GetSkillsDisabledImages()[i]->SetBrushTintColor(LockedTint);
			GetSkillsDisabledImages()[i]->Brush.OutlineSettings.Color = LockedBorderColor;
		}
		
		if(i < (level * 2))
		{
		    GetSkillsButtons()[i]->SetVisibility(ESlateVisibility::Visible);
		    continue;
		}

		GetSkillsButtons()[i]->SetVisibility(ESlateVisibility::Hidden);
	}

	for(int i = 0; i < GetLockImages().Num(); i++)
	{
		if(i < level)
		{
			GetLockImages()[i]->SetVisibility(ESlateVisibility::Hidden);
			continue;
		}
		
		GetLockImages()[i]->SetVisibility(ESlateVisibility::Visible);
	}
}

void UGPLevelUpStatusWidget::DisableSkillTree(int level)
{
	for(int i = 0; i < (level - 1) * 2; i++)
	{
		GetSkillsButtons()[i]->SetVisibility(ESlateVisibility::Hidden);
	}
}