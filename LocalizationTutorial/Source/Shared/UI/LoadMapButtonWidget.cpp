#include "Shared/UI/LoadMapButtonWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void ULoadMapButtonWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (IsValid(this->Button))
	{
		this->Button->OnClicked.AddUniqueDynamic(this, &ULoadMapButtonWidget::OnButtonClicked);
	}
}

void ULoadMapButtonWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (IsValid(this->Button))
	{
		this->Button->OnClicked.RemoveAll(this);
	}
}

void ULoadMapButtonWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (IsValid(this->MapTitleLabel))
	{
		this->MapTitleLabel->SetText(this->MapTitleText);
	}
}

void ULoadMapButtonWidget::OnButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), this->MapName);
}