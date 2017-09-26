// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetCloudScriptTaskInstance.generated.h"

UCLASS(MinimalAPI)
class UPFAdminGetCloudScriptTaskInstance : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminGetCloudScriptTaskInstanceResultDelegate OnSuccess;

    // Get detail information about a CloudScript task instance.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|ScheduledTask")
        static UPFAdminGetCloudScriptTaskInstance* GetCloudScriptTaskInstance(class APlayerController* PlayerController, const FBPAdminGetTaskInstanceRequest& InGetTaskInstanceRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminGetTaskInstanceRequest Request;
    PlayFab::UPlayFabAdminAPI::FGetCloudScriptTaskInstanceDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FGetCloudScriptTaskInstanceResult& Result);
};
