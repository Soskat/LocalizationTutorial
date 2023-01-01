#include "Shared/UI/ExamplesPageWidget.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UExamplesPageWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (IsValid(this->BackToMainMenuButton))
	{
		this->BackToMainMenuButton->OnClicked.AddUniqueDynamic(this, &UExamplesPageWidget::GoBackToMainMenu);
	}
}

void UExamplesPageWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (IsValid(this->BackToMainMenuButton))
	{
		this->BackToMainMenuButton->OnClicked.RemoveAll(this);
	}
}

void UExamplesPageWidget::GoBackToMainMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenuMap"));
}