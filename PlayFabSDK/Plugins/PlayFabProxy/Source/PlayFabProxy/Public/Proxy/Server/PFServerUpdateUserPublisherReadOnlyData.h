// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerUpdateUserPublisherReadOnlyData.generated.h"

UCLASS(MinimalAPI)
class UPFServerUpdateUserPublisherReadOnlyData : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPServerUpdateUserDataResultDelegate OnSuccess;

    // Updates the publisher-specific custom data for the user which can only be read by the client
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Player Data Management")
        static UPFServerUpdateUserPublisherReadOnlyData* UpdateUserPublisherReadOnlyData(class APlayerController* PlayerController, const FBPServerUpdateUserDataRequest& InUpdateUserDataRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerUpdateUserDataRequest Request;
    PlayFab::UPlayFabServerAPI::FUpdateUserPublisherReadOnlyDataDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FUpdateUserDataResult& Result);
};
