// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerGetUserAccountInfo.generated.h"

UCLASS(MinimalAPI)
class UPFServerGetUserAccountInfo : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPServerGetUserAccountInfoResultDelegate OnSuccess;

    // Retrieves the relevant details for a specified user
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Account Management")
        static UPFServerGetUserAccountInfo* GetUserAccountInfo(class APlayerController* PlayerController, const FBPServerGetUserAccountInfoRequest& InGetUserAccountInfoRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerGetUserAccountInfoRequest Request;
    PlayFab::UPlayFabServerAPI::FGetUserAccountInfoDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FGetUserAccountInfoResult& Result);
};
