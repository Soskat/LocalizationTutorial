#pragma once

#include "CoreMinimal.h"
#include "Internationalization/StringTableRegistry.h"

namespace MainGameLocalization
{
	static void LoadLocalizedTextsFromCsv()
	{
		/**
		* Following code is an example of creating a String Table usable both
		* from code and in blueprints.
		*
		* The general algorithm is simple:
		*	1. unregister potentially existing String Table with given ID -
		*	   this will prevent any potential errors while executing
		*	   the LOCTABLE_FROMFILE_GAME macro
		*	2. load and register new String Table from selected CSV file
		*/

		// 1. unregister potentially existing String Table:
		FStringTableRegistry::Get().UnregisterStringTable("ST_Animals");
		// 2. register new String Table with data loaded from given CSV file:
		LOCTABLE_FROMFILE_GAME("ST_Animals", "ST_Animals", "Localization/StringTablesCSV/ST_Animals.csv");
	}
}