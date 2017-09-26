// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientAddUsernamePassword.generated.h"

UCLASS(MinimalAPI)
class UPFClientAddUsernamePassword : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientAddUsernamePasswordResultDelegate OnSuccess;

    // Adds playfab username/password auth to an existing account created via an anonymous auth method, e.g. automatic device ID login.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Account Management")
        static UPFClientAddUsernamePassword* AddUsernamePassword(class APlayerController* PlayerController, const FBPClientAddUsernamePasswordRequest& InAddUsernamePasswordRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientAddUsernamePasswordRequest Request;
    PlayFab::UPlayFabClientAPI::FAddUsernamePasswordDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FAddUsernamePasswordResult& Result);
};
