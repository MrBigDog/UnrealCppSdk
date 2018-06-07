#pragma once

#include "CoreMinimal.h"
#include "PlayFabError.h"

namespace PlayFab
{
    PLAYFABCORE_API class PlayFabSettings
    {
    public:
        PLAYFABCORE_API static const FString sdkVersion;
        PLAYFABCORE_API static const FString buildIdentifier;
        PLAYFABCORE_API static const FString versionString;

        PLAYFABCORE_API static bool useDevelopmentEnvironment;
        PLAYFABCORE_API static FString serverURL;
        PLAYFABCORE_API static FString developmentEnvironmentURL;
        PLAYFABCORE_API static FString productionEnvironmentURL;
        PLAYFABCORE_API static FString titleId; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        PLAYFABCORE_API static FString clientSessionTicket; // Secret token that represents your session in the Client API. Set by calling any login method in the Client API
        PLAYFABCORE_API static FString developerSecretKey; // You must set this value for PlayFabSdk to work properly (Found in the Game Manager for your title, at the PlayFab Website)
        PLAYFABCORE_API static FString entityToken; // Secret token that represents your session in the Entity API. Set by calling GetEntityToken in the Entity API
        PLAYFABCORE_API static FString advertisingIdType; // Set this to the appropriate AD_TYPE_X constant below
        PLAYFABCORE_API static FString advertisingIdValue; // Set this to corresponding device value

        // DisableAdvertising is provided for completeness, but changing it is not suggested
        // Disabling this may prevent your advertising-related PlayFab marketplace partners from working correctly
        PLAYFABCORE_API static bool disableAdvertising;
        PLAYFABCORE_API static const FString AD_TYPE_IDFA;
        PLAYFABCORE_API static const FString AD_TYPE_ANDROID_ID;

        static FString getURL(const FString& callPath)
        {
            if (serverURL.Len() == 0)
                serverURL = TEXT("https://") + titleId + (useDevelopmentEnvironment ? developmentEnvironmentURL : productionEnvironmentURL);
            return serverURL + callPath;
        }
    };
}
