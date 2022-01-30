#include "CppStringTableLinkExampleWidget.h"

#include "Components/TextBlock.h"

void UCppStringTableLinkExampleWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (IsValid(this->DynamicText))
	{
		// Dynamically load text from a String Table:
		this->DynamicText->SetText(FText::FromStringTable(*this->StringTableName, *this->StringKey));
	}
}
