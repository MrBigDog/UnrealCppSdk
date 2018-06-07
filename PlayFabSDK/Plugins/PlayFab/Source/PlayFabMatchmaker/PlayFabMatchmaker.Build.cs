using UnrealBuildTool;

public class PlayFabMatchmaker : ModuleRules
{
    public PlayFabMatchmaker(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
            "PlayFabMatchmaker/Public"
        });

        PrivateIncludePaths.AddRange(new string[] {
            "PlayFabMatchmaker/Private"
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
