#pragma once

#include "CoreMinimal.h"
#include "Internationalization/StringTableRegistry.h"

namespace TextLocalizationExample
{
	static void GenerateWeaponsStringTable()
	{
		/**
		* Following code will create a String Table named ST_Weapons and populate
		* it with three text entries. For this purpose we will use LOCTABLE family of macros.
		*/
		LOCTABLE_NEW("ST_Weapons", "ST_Weapons");
		LOCTABLE_SETSTRING("ST_Weapons", "st_cpp_weapons_sword", "sword");
		LOCTABLE_SETMETA("ST_Weapons", "st_cpp_weapons_sword", "Comment", "This is a comment about sword");
		LOCTABLE_SETSTRING("ST_Weapons", "st_cpp_weapons_axe", "axe");
		LOCTABLE_SETMETA("ST_Weapons", "st_cpp_weapons_axe", "Comment", "This is a comment about axe");
		LOCTABLE_SETSTRING("ST_Weapons", "st_cpp_weapons_bow", "bow");
		LOCTABLE_SETMETA("ST_Weapons", "st_cpp_weapons_bow", "Comment", "This is a comment about bow");
	}
}