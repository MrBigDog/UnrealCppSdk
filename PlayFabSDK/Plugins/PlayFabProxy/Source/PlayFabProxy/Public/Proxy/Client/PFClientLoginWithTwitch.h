// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLoginWithTwitch.generated.h"

UCLASS(MinimalAPI)
class UPFClientLoginWithTwitch : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientLoginResultDelegate OnSuccess;

    // Signs the user in using a Twitch access token.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Authentication")
        static UPFClientLoginWithTwitch* LoginWithTwitch(class APlayerController* PlayerController, const FBPClientLoginWithTwitchRequest& InLoginWithTwitchRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientLoginWithTwitchRequest Request;
    PlayFab::UPlayFabClientAPI::FLoginWithTwitchDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result);
};
