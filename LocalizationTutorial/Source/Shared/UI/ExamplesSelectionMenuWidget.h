#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "ExamplesSelectionMenuWidget.generated.h"

class UButton;

UCLASS()
class SHARED_API UExamplesSelectionMenuWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UPROPERTY(Meta = (BindWidget))
	UButton* QuitButton = nullptr;
	UFUNCTION()
	void OnQuitButtonClicked();
};