#include "TextLocalizationModule.h"

#include "Modules/ModuleManager.h"
#include "TextLocalization/Resources/AnimalsStringTableFromCsvLoader.h"
#include "TextLocalization/Resources/WeaponsStringTableGenerator.h"

IMPLEMENT_GAME_MODULE(FTextLocalizationModule, TextLocalization);

void FTextLocalizationModule::StartupModule()
{
	FDefaultGameModuleImpl::StartupModule();

	// Create new String Table using LOCTABLE family of macros:
	TextLocalizationExample::GenerateWeaponsStringTable();

	// Create new String Tables for localized texts using the data loaded from CSV files:
	TextLocalizationExample::LoadLocalizedTextsFromCsv();
}
