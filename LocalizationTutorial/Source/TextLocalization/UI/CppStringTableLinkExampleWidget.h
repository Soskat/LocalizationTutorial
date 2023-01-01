#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CppStringTableLinkExampleWidget.generated.h"

class UTextBlock;

/**
 * This class is an example of loading dynamically texts from String Tables created in C++.
 *
 * This is a base class for widget WBP_CppStringTable_DynamicLoad.
 */
UCLASS()
class TEXTLOCALIZATION_API UCppStringTableLinkExampleWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void SynchronizeProperties() override;

private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* DynamicText;

	UPROPERTY(EditAnywhere, meta = (Tooltip = "Unique ID of a String Table used to identify it."))
	FString StringTableName;
	UPROPERTY(EditAnywhere, meta = (Tooltip = "Unique key of a text inside a String Table."))
	FString StringKey;
};
