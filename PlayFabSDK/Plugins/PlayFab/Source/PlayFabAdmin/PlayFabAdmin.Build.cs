using UnrealBuildTool;

public class PlayFabAdmin : ModuleRules
{
    public PlayFabAdmin(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
            "PlayFabAdmin/Public"
        });

        PrivateIncludePaths.AddRange(new string[] {
            "PlayFabAdmin/Private"
        });

        PublicDependencyModuleNames.AddRange(new string[]{
            "Core",
            "CoreUObject",
            "HTTP",
            "Json",

            "PlayFabCore"
        });

        if (Target.bBuildEditor == true)
        {
            PrivateDependencyModuleNames.AddRange(new string[] {
                "Settings"
            });
        }
    }
}
