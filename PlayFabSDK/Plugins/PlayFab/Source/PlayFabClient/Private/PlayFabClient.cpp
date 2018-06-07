#include "PlayFabClient.h"

// Settings
#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#endif // WITH_EDITOR
#include "PlayFabSettings.h"

#include "Client/PlayFabClientAPI.h"

#define LOCTEXT_NAMESPACE "FPlayFabClientModule"

class FPlayFabClientModule : public IPlayFabClientModuleInterface
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    PlayFabClientPtr GetClientAPI() const override { return ClientAPI; };

    PlayFabClientPtr ClientAPI;
};

void FPlayFabClientModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

    // create the API
    ClientAPI = MakeShareable(new PlayFab::UPlayFabClientAPI());

}

void FPlayFabClientModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPlayFabClientModule, PlayFabClient)
