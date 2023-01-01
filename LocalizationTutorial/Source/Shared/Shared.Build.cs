using UnrealBuildTool;

public class Shared : ModuleRules
{
	public Shared(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"UMG",
		});

		//PrivateDependencyModuleNames.AddRange(new string[] {  });
	}
}
