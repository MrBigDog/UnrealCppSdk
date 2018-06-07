#include "PlayFabCore.h"

// Settings
#include "PlayFabCoreRuntimeSettings.h"
#if WITH_EDITOR
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#endif // WITH_EDITOR
#include "PlayFabSettings.h"

DEFINE_LOG_CATEGORY(LogPlayFabCore);

#define LOCTEXT_NAMESPACE "FPlayFabCoreModule"

class FPlayFabCoreModule : public IPlayFabCoreModuleInterface
{
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    // Settings
    void RegisterSettings();
    void UnregisterSettings();

    /** Callback for when the settings were saved. */
    bool HandleSettingsSaved();

    FString GetTitleId() const override { return PlayFab::PlayFabSettings::titleId; };

};

void FPlayFabCoreModule::StartupModule()
{
    // This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    RegisterSettings();
    HandleSettingsSaved();

}

void FPlayFabCoreModule::ShutdownModule()
{
    // This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
    // we call this function before unloading the module.
    UnregisterSettings();
}

void FPlayFabCoreModule::RegisterSettings()
{
#if WITH_EDITOR
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "PlayFab",
            LOCTEXT("PlayFabSettingsName", "PlayFab"),
            LOCTEXT("PlayFabSettingsDescription", "Configure the PlayFab plugin"),
            GetMutableDefault<UPlayFabCoreRuntimeSettings>()
        );

        if (SettingsSection.IsValid())
        {
            SettingsSection->OnModified().BindRaw(this, &FPlayFabCoreModule::HandleSettingsSaved);
        }
    }
#endif // WITH_EDITOR
}

void FPlayFabCoreModule::UnregisterSettings()
{
#if WITH_EDITOR
    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->UnregisterSettings("Project", "Plugins", "PlayFab");
    }
#endif
}

bool FPlayFabCoreModule::HandleSettingsSaved()
{
    // copy to the internal structure
    PlayFab::PlayFabSettings::serverURL = FString(); // flush the previous Server URL
    PlayFab::PlayFabSettings::useDevelopmentEnvironment = GetDefault<UPlayFabCoreRuntimeSettings>()->bUseDevelopmentEnvironment;
    PlayFab::PlayFabSettings::developmentEnvironmentURL = GetDefault<UPlayFabCoreRuntimeSettings>()->DevelopmentEnvironmentURL;
    PlayFab::PlayFabSettings::productionEnvironmentURL = GetDefault<UPlayFabCoreRuntimeSettings>()->ProductionEnvironmentURL;
    PlayFab::PlayFabSettings::titleId = GetDefault<UPlayFabCoreRuntimeSettings>()->TitleId;
    PlayFab::PlayFabSettings::developerSecretKey = GetDefault<UPlayFabCoreRuntimeSettings>()->DeveloperSecretKey;

    return true;
}
#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPlayFabCoreModule, PlayFabCore)
