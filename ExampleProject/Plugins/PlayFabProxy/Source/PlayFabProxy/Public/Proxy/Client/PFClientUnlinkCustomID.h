// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientUnlinkCustomID.generated.h"

UCLASS(MinimalAPI)
class UPFClientUnlinkCustomID : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Unlinks the related custom identifier from the user's PlayFab account
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Account Management")
        static UPFClientUnlinkCustomID* UnlinkCustomID(class APlayerController* PlayerController, const FBPClientUnlinkCustomIDRequest& InUnlinkCustomIDRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientUnlinkCustomIDRequest Request;
    PlayFab::UPlayFabClientAPI::FUnlinkCustomIDDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FUnlinkCustomIDResult& Result);
};
