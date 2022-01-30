#include "LocMacroSomeDLCExampleWidget.h"

#include "Components/TextBlock.h"

void ULocMacroSomeDLCExampleWidget::FillAllTexts()
{
	Super::FillAllTexts();

	if (IsValid(this->TextLiteral_3))
	{
		// Create a text literal within a different namespace than the ones defined in parent class:
		this->TextLiteral_3->SetText(NSLOCTEXT("Cpp_Namespace_3", "Cpp_TextLiteral_3", "This is the third text literal created in code."));
	}
}