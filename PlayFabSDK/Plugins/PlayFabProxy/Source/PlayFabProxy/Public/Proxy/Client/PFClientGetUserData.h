// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetUserData.generated.h"

UCLASS(MinimalAPI)
class UPFClientGetUserData : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientGetUserDataResultDelegate OnSuccess;

    // Retrieves the title-specific custom data for the user which is readable and writable by the client
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Player Data Management")
        static UPFClientGetUserData* GetUserData(class APlayerController* PlayerController, const FBPClientGetUserDataRequest& InGetUserDataRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientGetUserDataRequest Request;
    PlayFab::UPlayFabClientAPI::FGetUserDataDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FGetUserDataResult& Result);
};
