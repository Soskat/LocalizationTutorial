using UnrealBuildTool;

public class TextLocalization : ModuleRules
{
	public TextLocalization(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"UMG",
			"Shared",
		});

		//PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
