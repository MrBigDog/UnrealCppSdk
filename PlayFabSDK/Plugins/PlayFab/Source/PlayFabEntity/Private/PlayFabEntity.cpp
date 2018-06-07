#include "PlayFabEntity.h"

// Settings
#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#endif // WITH_EDITOR
#include "PlayFabSettings.h"

#include "Entity/PlayFabEntityAPI.h"

#define LOCTEXT_NAMESPACE "FPlayFabEntityModule"

class FPlayFabEntityModule : public IPlayFabEntityModuleInterface
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    PlayFabEntityPtr GetEntityAPI() const override { return EntityAPI; };

    PlayFabEntityPtr EntityAPI;
};

void FPlayFabEntityModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

    // create the API
    EntityAPI = MakeShareable(new PlayFab::UPlayFabEntityAPI());

}

void FPlayFabEntityModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPlayFabEntityModule, PlayFabEntity)
