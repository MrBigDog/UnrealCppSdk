using UnrealBuildTool;
using System.IO;


public class PlayFabCombo : ModuleRules
{
    public PlayFabCombo(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {
            "PlayFabCombo/Public"
        });

        PrivateIncludePaths.AddRange(new string[] {
            "PlayFabCombo/Private"
        });

        PublicDependencyModuleNames.AddRange(new string[]{
            "Core",
            "CoreUObject",
            "HTTP",
            "Json",

            "PlayFabAdmin",
            "PlayFabClient",
            "PlayFabEntity",
            "PlayFabMatchmaker",
            "PlayFabServer"
        });

        if (Target.bBuildEditor == true)
        {
            PrivateDependencyModuleNames.AddRange(new string[] {
                "Settings"
            });
        }
    }
}
