// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetCloudScriptRevision.generated.h"

UCLASS(MinimalAPI)
class UPFAdminGetCloudScriptRevision : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminGetCloudScriptRevisionResultDelegate OnSuccess;

    // Gets the contents and information of a specific Cloud Script revision.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Server-Side Cloud Script")
        static UPFAdminGetCloudScriptRevision* GetCloudScriptRevision(class APlayerController* PlayerController, const FBPAdminGetCloudScriptRevisionRequest& InGetCloudScriptRevisionRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminGetCloudScriptRevisionRequest Request;
    PlayFab::UPlayFabAdminAPI::FGetCloudScriptRevisionDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FGetCloudScriptRevisionResult& Result);
};