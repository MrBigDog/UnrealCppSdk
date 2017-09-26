// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientExecuteCloudScript.generated.h"

UCLASS(MinimalAPI)
class UPFClientExecuteCloudScript : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientExecuteCloudScriptResultDelegate OnSuccess;

    // Executes a CloudScript function, with the 'currentPlayerId' set to the PlayFab ID of the authenticated player.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Server-Side Cloud Script")
        static UPFClientExecuteCloudScript* ExecuteCloudScript(class APlayerController* PlayerController, const FBPClientExecuteCloudScriptRequest& InExecuteCloudScriptRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientExecuteCloudScriptRequest Request;
    PlayFab::UPlayFabClientAPI::FExecuteCloudScriptDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FExecuteCloudScriptResult& Result);
};
