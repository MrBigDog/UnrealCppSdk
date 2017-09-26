// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminModifyServerBuild.generated.h"

UCLASS(MinimalAPI)
class UPFAdminModifyServerBuild : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminModifyServerBuildResultDelegate OnSuccess;

    // Updates the build details for the specified game server executable
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Custom Server Management")
        static UPFAdminModifyServerBuild* ModifyServerBuild(class APlayerController* PlayerController, const FBPAdminModifyServerBuildRequest& InModifyServerBuildRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminModifyServerBuildRequest Request;
    PlayFab::UPlayFabAdminAPI::FModifyServerBuildDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FModifyServerBuildResult& Result);
};
