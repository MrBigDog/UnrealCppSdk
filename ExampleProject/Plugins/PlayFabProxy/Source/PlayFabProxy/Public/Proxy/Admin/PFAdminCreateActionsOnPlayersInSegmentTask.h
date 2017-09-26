// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminCreateActionsOnPlayersInSegmentTask.generated.h"

UCLASS(MinimalAPI)
class UPFAdminCreateActionsOnPlayersInSegmentTask : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminCreateTaskResultDelegate OnSuccess;

    // Create an ActionsOnPlayersInSegment task, which iterates through all players in a segment to execute action.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|ScheduledTask")
        static UPFAdminCreateActionsOnPlayersInSegmentTask* CreateActionsOnPlayersInSegmentTask(class APlayerController* PlayerController, const FBPAdminCreateActionsOnPlayerSegmentTaskRequest& InCreateActionsOnPlayerSegmentTaskRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminCreateActionsOnPlayerSegmentTaskRequest Request;
    PlayFab::UPlayFabAdminAPI::FCreateActionsOnPlayersInSegmentTaskDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FCreateTaskResult& Result);
};
