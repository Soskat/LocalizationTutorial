#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "LoadMapButtonWidget.generated.h"

class UButton;
class UTextBlock;

UCLASS()
class SHARED_API ULoadMapButtonWidget : public UUserWidget
{
	GENERATED_BODY()

private:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void SynchronizeProperties() override;

	UPROPERTY(Meta = (BindWidget))
	UButton* Button = nullptr;
	UFUNCTION()
	void OnButtonClicked();
	
	UPROPERTY(Meta = (BindWidget))
	UTextBlock* MapTitleLabel = nullptr;

	UPROPERTY(EditAnywhere)
	FText MapTitleText = FText::AsCultureInvariant(TEXT("Example Title"));
	UPROPERTY(EditAnywhere)
	FName MapName = "None";
};