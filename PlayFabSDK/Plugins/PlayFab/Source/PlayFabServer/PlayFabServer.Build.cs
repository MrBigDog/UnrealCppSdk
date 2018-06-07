using UnrealBuildTool;

public class PlayFabServer : ModuleRules
{
    public PlayFabServer(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
            "PlayFabServer/Public"
        });

        PrivateIncludePaths.AddRange(new string[] {
            "PlayFabServer/Private"
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
