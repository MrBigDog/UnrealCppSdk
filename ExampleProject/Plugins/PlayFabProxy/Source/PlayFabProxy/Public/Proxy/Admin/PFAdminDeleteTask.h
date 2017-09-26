// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminDeleteTask.generated.h"

UCLASS(MinimalAPI)
class UPFAdminDeleteTask : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Delete a task.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|ScheduledTask")
        static UPFAdminDeleteTask* DeleteTask(class APlayerController* PlayerController, const FBPAdminDeleteTaskRequest& InDeleteTaskRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminDeleteTaskRequest Request;
    PlayFab::UPlayFabAdminAPI::FDeleteTaskDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FEmptyResult& Result);
};
