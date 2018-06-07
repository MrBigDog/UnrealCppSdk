#include "PlayFabCoreRuntimeSettings.h"

//////////////////////////////////////////////////////////////////////////
// UPlayFabRuntimeSettings

UPlayFabCoreRuntimeSettings::UPlayFabCoreRuntimeSettings()
    : bUseDevelopmentEnvironment(false)
    , DevelopmentEnvironmentURL(TEXT(".playfabsandbox.com"))
    , ProductionEnvironmentURL(TEXT(".playfabapi.com"))
    , TitleId()
    , DeveloperSecretKey()
{
}
