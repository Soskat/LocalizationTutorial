#include "LocalizationTutorial.h"
#include "Modules/ModuleManager.h"
#include "LocalizationTutorial/MainGame/CsvBaseStringTableLoaderMainGame.h"
#include "LocalizationTutorial/MainGame/StringTableGeneratorMainGame.h"
#include "LocalizationTutorial/SomeDLC/CsvBaseStringTableLoaderSomeDLC.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FLocalizationTutorial, LocalizationTutorial, "LocalizationTutorial" );

void FLocalizationTutorial::StartupModule()
{
	FDefaultGameModuleImpl::StartupModule();

	// Create new String Table using LOCTABLE family of macros:
	MainGameLocalization::GenerateWeaponsStringTable();
	// Create new String Tables for localized texts using the data loaded from CSV files:
	MainGameLocalization::LoadLocalizedTextsFromCsv();
	SomeDLCLocalization::LoadLocalizedTextsFromCsv();
}
