// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientUnlinkAndroidDeviceID.generated.h"

UCLASS(MinimalAPI)
class UPFClientUnlinkAndroidDeviceID : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Unlinks the related Android device identifier from the user's PlayFab account
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Account Management")
        static UPFClientUnlinkAndroidDeviceID* UnlinkAndroidDeviceID(class APlayerController* PlayerController, const FBPClientUnlinkAndroidDeviceIDRequest& InUnlinkAndroidDeviceIDRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientUnlinkAndroidDeviceIDRequest Request;
    PlayFab::UPlayFabClientAPI::FUnlinkAndroidDeviceIDDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FUnlinkAndroidDeviceIDResult& Result);
};
