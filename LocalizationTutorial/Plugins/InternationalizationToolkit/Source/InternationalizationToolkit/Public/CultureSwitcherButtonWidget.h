#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "CultureSwitcherButtonWidget.generated.h"

class UButton;
class UTextBlock;

DECLARE_DELEGATE(FCultureChanged);

/**
 * Base class for a simple button user widget, that exetutes a method from 
 * the KismetInternationalizationLibrary method for switching current Culture in use.
 */
UCLASS()
class INTERNATIONALIZATIONTOOLKIT_API UCultureSwitcherButtonWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetButtonCulture(const FString& InCultureCode);

	FCultureChanged CultureChanged;

private:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	UFUNCTION()
	void SwitchCurrentCulture();

	UPROPERTY(meta = (BindWidget))
	UButton* Button;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ButtonLabel;

	FString CultureCode;
};