#pragma once

#include "CoreMinimal.h"
#include "LocalizationTutorial/MainGame/LocMacroExampleWidget.h"
#include "LocMacroSomeDLCExampleWidget.generated.h"

class UTextBlock;

/**
 * This class is an example of how to create localized texts in C++ by using the LOCTEXT family of macros.
 * Online duccumentation: https://docs.unrealengine.com/4.27/en-US/ProductionPipelines/Localization/Formatting/
 */
UCLASS()
class LOCALIZATIONTUTORIAL_API ULocMacroSomeDLCExampleWidget : public ULocMacroExampleWidget
{
	GENERATED_BODY()

public:
	virtual void FillAllTexts() override;

private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextLiteral_3;
};
