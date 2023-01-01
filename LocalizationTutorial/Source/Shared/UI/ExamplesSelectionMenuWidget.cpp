#include "Shared/UI/ExamplesSelectionMenuWidget.h"

#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

void UExamplesSelectionMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (IsValid(this->QuitButton))
	{
		this->QuitButton->OnClicked.AddUniqueDynamic(this, &UExamplesSelectionMenuWidget::OnQuitButtonClicked);
	}
}

void UExamplesSelectionMenuWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (IsValid(this->QuitButton))
	{
		this->QuitButton->OnClicked.RemoveAll(this);
	}
}

void UExamplesSelectionMenuWidget::OnQuitButtonClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Type::Quit, false);
}