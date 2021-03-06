// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientLoginWithPlayFab.generated.h"

UCLASS(MinimalAPI)
class UPFClientLoginWithPlayFab : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientLoginResultDelegate OnSuccess;

    // Signs the user into the PlayFab account, returning a session identifier that can subsequently be used for API calls which require an authenticated user. Unlike most other login API calls, LoginWithPlayFab does not permit the creation of new accounts via the CreateAccountFlag. Username/Password credentials may be used to create accounts via RegisterPlayFabUser, or added to existing accounts using AddUsernamePassword.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Authentication")
        static UPFClientLoginWithPlayFab* LoginWithPlayFab(class APlayerController* PlayerController, const FBPClientLoginWithPlayFabRequest& InLoginWithPlayFabRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientLoginWithPlayFabRequest Request;
    PlayFab::UPlayFabClientAPI::FLoginWithPlayFabDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result);
};
