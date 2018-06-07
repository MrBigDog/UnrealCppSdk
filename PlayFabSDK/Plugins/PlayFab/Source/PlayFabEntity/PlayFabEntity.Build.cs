using UnrealBuildTool;

public class PlayFabEntity : ModuleRules
{
    public PlayFabEntity(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
            "PlayFabEntity/Public"
        });

        PrivateIncludePaths.AddRange(new string[] {
            "PlayFabEntity/Private"
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
