#include "LocMacroAnotherDLCExampleWidget.h"

#include "Components/TextBlock.h"

void ULocMacroAnotherDLCExampleWidget::FillAllTexts()
{
	Super::FillAllTexts();

	if (IsValid(this->TextLiteral_3))
	{
		// Create a text literal within the same 1st. namespace that is defined in parent class:
		this->TextLiteral_3->SetText(NSLOCTEXT("Cpp_Namespace_1", "Cpp_TextLiteral_3", "This is the third text literal created in code."));
	}
}
