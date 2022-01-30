#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LocMacroExampleWidget.generated.h"

class UTextBlock;

/**
 * This class is an example of how to create localized texts in C++ by using the LOCTEXT family of macros.
 * Online duccumentation: https://docs.unrealengine.com/4.27/en-US/ProductionPipelines/Localization/Formatting/
 */
UCLASS()
class LOCALIZATIONTUTORIAL_API ULocMacroExampleWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void SynchronizeProperties() override;
	virtual void FillAllTexts();

private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextLiteral_1;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextLiteral_2;
};
