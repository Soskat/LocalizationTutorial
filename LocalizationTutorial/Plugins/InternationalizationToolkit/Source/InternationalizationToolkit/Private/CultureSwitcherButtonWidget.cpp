#include "CultureSwitcherButtonWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/KismetInternationalizationLibrary.h"

void UCultureSwitcherButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (IsValid(this->Button))
	{
		this->Button->OnClicked.AddUniqueDynamic(this, &UCultureSwitcherButtonWidget::SwitchCurrentCulture);
	}
}

void UCultureSwitcherButtonWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (IsValid(this->Button))
	{
		this->Button->OnClicked.Clear();
	}
}

void UCultureSwitcherButtonWidget::SetButtonCulture(const FString& InCultureCode)
{
	this->CultureCode = InCultureCode;
	if (IsValid(this->ButtonLabel))
	{
		this->ButtonLabel->SetText(FText::FromString(this->CultureCode));
	}
}

void UCultureSwitcherButtonWidget::SwitchCurrentCulture()
{
	// Set currently used Culture to one written in this->CultureCode variable:
	UKismetInternationalizationLibrary::SetCurrentCulture(*this->CultureCode);

	this->CultureChanged.ExecuteIfBound();
}
