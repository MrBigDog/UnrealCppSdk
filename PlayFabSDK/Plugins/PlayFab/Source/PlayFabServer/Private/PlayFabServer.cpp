#include "PlayFabServer.h"

// Settings
#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#endif // WITH_EDITOR
#include "PlayFabSettings.h"

#include "Server/PlayFabServerAPI.h"

#define LOCTEXT_NAMESPACE "FPlayFabServerModule"

class FPlayFabServerModule : public IPlayFabServerModuleInterface
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    PlayFabServerPtr GetServerAPI() const override { return ServerAPI; };

    PlayFabServerPtr ServerAPI;
};

void FPlayFabServerModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

    // create the API
    ServerAPI = MakeShareable(new PlayFab::UPlayFabServerAPI());

}

void FPlayFabServerModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPlayFabServerModule, PlayFabServer)
