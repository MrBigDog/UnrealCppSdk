using UnrealBuildTool;

public class PlayFabCore : ModuleRules
{
    public PlayFabCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
            "PlayFabCore/Public"
        });

        PrivateIncludePaths.AddRange(new string[] {
            "PlayFabCore/Private"
        });

        PublicDependencyModuleNames.AddRange(new string[]{
            "Core",
            "CoreUObject",
            "HTTP",
            "Json"
        });

        if (Target.bBuildEditor == true)
        {
            PrivateDependencyModuleNames.AddRange(new string[] {
                "Settings"
            });
        }
    }
}
