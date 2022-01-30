#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "CultureSwitcherPanelWidget.generated.h"

class UPanelWidget;
class UTextBlock;
class UCultureSwitcherButtonWidget;

/**
 * Base class for a simple panel user widget.
 * 
 * It spawns a set of UCultureSwitcherButtonWidget buttons, that represents all found localizaed cultures.
 * Each one of these buttons is capable of switching current culture to the one assigned to this button.
 */
UCLASS()
class INTERNATIONALIZATIONTOOLKIT_API UCultureSwitcherPanelWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	virtual void NativeConstruct() override;
	void GenerateCultureSwitcherButtons();
	UFUNCTION()
	void OnCultureChanged();

	UPROPERTY(meta = (BindWidget))
	UPanelWidget* ButtonsPanel;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* CurrentCultureText;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCultureSwitcherButtonWidget> CultureSwitcherWidgetType;
};
