#pragma once

#include "CoreMinimal.h"
#include "Internationalization/StringTableRegistry.h"

namespace SomeDLCLocalization
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

		// Note that we can load multiple String Tables from different CSV files
		// and assigned them to the one, common namespace:
		FStringTableRegistry::Get().UnregisterStringTable("ST_Shapes");
		LOCTABLE_FROMFILE_GAME("ST_Shapes", "ST_Shapes", "Localization/StringTablesCSV/ST_Shapes.csv");
	}
}