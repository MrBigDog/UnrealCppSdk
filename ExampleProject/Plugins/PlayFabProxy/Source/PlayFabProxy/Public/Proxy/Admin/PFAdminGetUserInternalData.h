// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetUserInternalData.generated.h"

UCLASS(MinimalAPI)
class UPFAdminGetUserInternalData : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminGetUserDataResultDelegate OnSuccess;

    // Retrieves the title-specific custom data for the user which cannot be accessed by the client
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Player Data Management")
        static UPFAdminGetUserInternalData* GetUserInternalData(class APlayerController* PlayerController, const FBPAdminGetUserDataRequest& InGetUserDataRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminGetUserDataRequest Request;
    PlayFab::UPlayFabAdminAPI::FGetUserInternalDataDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FGetUserDataResult& Result);
};
