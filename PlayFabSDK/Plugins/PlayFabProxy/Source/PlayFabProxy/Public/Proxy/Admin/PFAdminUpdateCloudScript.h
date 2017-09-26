// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminUpdateCloudScript.generated.h"

UCLASS(MinimalAPI)
class UPFAdminUpdateCloudScript : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminUpdateCloudScriptResultDelegate OnSuccess;

    // Creates a new Cloud Script revision and uploads source code to it. Note that at this time, only one file should be submitted in the revision.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Server-Side Cloud Script")
        static UPFAdminUpdateCloudScript* UpdateCloudScript(class APlayerController* PlayerController, const FBPAdminUpdateCloudScriptRequest& InUpdateCloudScriptRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminUpdateCloudScriptRequest Request;
    PlayFab::UPlayFabAdminAPI::FUpdateCloudScriptDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FUpdateCloudScriptResult& Result);
};
