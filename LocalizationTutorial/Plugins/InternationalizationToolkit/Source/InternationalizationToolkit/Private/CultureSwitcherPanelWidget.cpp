#include "CultureSwitcherPanelWidget.h"

#include "Components/PanelWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetInternationalizationLibrary.h"
#include "InternationalizationToolkit/Public/CultureSwitcherButtonWidget.h"

DEFINE_LOG_CATEGORY_STATIC(LogInternationalizationToolkit, Log, All);

void UCultureSwitcherPanelWidget::NativeConstruct()
{
	Super::NativeConstruct();
	GenerateCultureSwitcherButtons();
	OnCultureChanged();
}

void UCultureSwitcherPanelWidget::GenerateCultureSwitcherButtons()
{
	if (IsValid(this->ButtonsPanel) == false)
	{
		UE_LOG(LogInternationalizationToolkit, Error, TEXT("Failed to generate CultureSwitcher buttons | ButtonsPanel is not valid!"));
	}
	if (IsValid(this->CultureSwitcherWidgetType) == false)
	{
		UE_LOG(LogInternationalizationToolkit, Error, TEXT("Failed to generate CultureSwitcher buttons | CultureSwitcherWidgetType is not valid!"));
	}

	// Generate CultureSwitcher buttons for every localized Culture that is loaded in runtime:
	this->ButtonsPanel->ClearChildren();
	const auto LocalizedCultures = UKismetInternationalizationLibrary::GetLocalizedCultures();
	for (const auto& Culture : LocalizedCultures)
	{
		auto* CultureSwitcher = Cast<UCultureSwitcherButtonWidget>(CreateWidget(this, this->CultureSwitcherWidgetType));
		if (IsValid(CultureSwitcher) == false)
		{
			continue;
		}

		CultureSwitcher->SetButtonCulture(Culture);
		CultureSwitcher->CultureChanged.BindUObject(this, &UCultureSwitcherPanelWidget::OnCultureChanged);
		this->ButtonsPanel->AddChild(CultureSwitcher);
	}
}

void UCultureSwitcherPanelWidget::OnCultureChanged()
{
	if (IsValid(this->CurrentCultureText))
	{
		const auto CurrentCulture = UKismetInternationalizationLibrary::GetCurrentCulture();
		this->CurrentCultureText->SetText(FText::FromString(CurrentCulture));
	}
}
