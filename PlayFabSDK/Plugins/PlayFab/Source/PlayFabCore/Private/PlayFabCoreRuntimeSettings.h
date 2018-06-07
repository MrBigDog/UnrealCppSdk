#pragma once

#include "CoreMinimal.h"
#include "PlayFabCoreRuntimeSettings.generated.h"

/**
* Implements the settings for the PlayFab plugin.
*/
UCLASS(config = Engine, defaultconfig)
class PLAYFABCORE_API UPlayFabCoreRuntimeSettings : public UObject
{
    GENERATED_BODY()
public:
    UPlayFabCoreRuntimeSettings();

    // Define if we want to use the sandbox URL
    UPROPERTY(EditAnywhere, config, Category = Settings)
    bool bUseDevelopmentEnvironment;

    // URL endpoint of the PlayFab sandbox
    UPROPERTY(EditAnywhere, config, Category = Settings)
    FString DevelopmentEnvironmentURL;

    // URL endpoint of the PlayFab production environment
    UPROPERTY(EditAnywhere, config, Category = Settings)
    FString ProductionEnvironmentURL;

    // Game Title ID
    UPROPERTY(EditAnywhere, config, Category = Settings)
    FString TitleId;

    // Secret Key, Do not add this to the clients!
    UPROPERTY(EditAnywhere, config, Category = Settings)
    FString DeveloperSecretKey;
};
