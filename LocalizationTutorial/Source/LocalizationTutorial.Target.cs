// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class LocalizationTutorialTarget : TargetRules
{
	public LocalizationTutorialTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		
		ExtraModuleNames.Add("TextLocalization");
		ExtraModuleNames.Add("Shared");
	}
}
