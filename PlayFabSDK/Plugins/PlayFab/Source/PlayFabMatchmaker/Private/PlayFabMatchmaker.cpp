#include "PlayFabMatchmaker.h"

// Settings
#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#endif // WITH_EDITOR
#include "PlayFabSettings.h"

#include "Matchmaker/PlayFabMatchmakerAPI.h"

#define LOCTEXT_NAMESPACE "FPlayFabMatchmakerModule"

class FPlayFabMatchmakerModule : public IPlayFabMatchmakerModuleInterface
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    PlayFabMatchmakerPtr GetMatchmakerAPI() const override { return MatchmakerAPI; };

    PlayFabMatchmakerPtr MatchmakerAPI;
};

void FPlayFabMatchmakerModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

    // create the API
    MatchmakerAPI = MakeShareable(new PlayFab::UPlayFabMatchmakerAPI());

}

void FPlayFabMatchmakerModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPlayFabMatchmakerModule, PlayFabMatchmaker)
