#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "ExamplesPageWidget.generated.h"

class UButton;

UCLASS()
class SHARED_API UExamplesPageWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UPROPERTY(Meta = (BindWidget))
	UButton* BackToMainMenuButton = nullptr;
	UFUNCTION()
	void GoBackToMainMenu();
};