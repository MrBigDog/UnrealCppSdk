#pragma once

#include "CoreMinimal.h"
#include "PlayFabBaseModel.h"
#include "PlayFabError.h"
#include "Http.h"

namespace PlayFab
{
PLAYFABCORE_API class PlayFabRequestHandler
    {
    private:
        static int pendingCalls;
    public:
        PLAYFABCORE_API static int GetPendingCalls();
        PLAYFABCORE_API static TSharedRef<IHttpRequest> SendRequest(const FString& url, const FString& callBody, const FString& authKey, const FString& authValue);
        PLAYFABCORE_API static bool DecodeRequest(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, PlayFab::FPlayFabBaseModel& OutResult, PlayFab::FPlayFabError& OutError);
        PLAYFABCORE_API static bool DecodeError(TSharedPtr<FJsonObject> JsonObject, PlayFab::FPlayFabError& OutError);
    };
};
