#include "PlayFabAdmin.h"

// Settings
#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#endif // WITH_EDITOR
#include "PlayFabSettings.h"

#include "Admin/PlayFabAdminAPI.h"

#define LOCTEXT_NAMESPACE "FPlayFabAdminModule"

class FPlayFabAdminModule : public IPlayFabAdminModuleInterface
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    PlayFabAdminPtr GetAdminAPI() const override { return AdminAPI; };

    PlayFabAdminPtr AdminAPI;
};

void FPlayFabAdminModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

    // create the API
    AdminAPI = MakeShareable(new PlayFab::UPlayFabAdminAPI());

}

void FPlayFabAdminModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPlayFabAdminModule, PlayFabAdmin)
