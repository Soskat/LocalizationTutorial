#include "LocMacroExampleWidget.h"

#include "Components/TextBlock.h"

void ULocMacroExampleWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	FillAllTexts();
}

/**
* Define the namespace to use with LOCTEXT.
* This is only valid within a single file, and must be undefined before the end of the file.
*/
#define LOCTEXT_NAMESPACE "Cpp_Namespace_1"

void ULocMacroExampleWidget::FillAllTexts()
{
	if (IsValid(this->TextLiteral_1))
	{
		// Create a text literal within the namespace defined in line 16:
		this->TextLiteral_1->SetText(LOCTEXT("Cpp_TextLiteral_1", "This is the first text literal created in code."));
	}
	if (IsValid(this->TextLiteral_2))
	{
		// Create a text literal within a different namespace than the one defined in line 16:
		this->TextLiteral_2->SetText(NSLOCTEXT("Cpp_Namespace_2", "Cpp_TextLiteral_2", "This is the second text literal created in code."));
	}
}

// Undefine the namespace before the end of the file
#undef LOCTEXT_NAMESPACE
