// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminRemoveServerBuild.generated.h"

UCLASS(MinimalAPI)
class UPFAdminRemoveServerBuild : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Removes the game server executable specified from the set of those a client is permitted to request in a call to StartGame
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Custom Server Management")
        static UPFAdminRemoveServerBuild* RemoveServerBuild(class APlayerController* PlayerController, const FBPAdminRemoveServerBuildRequest& InRemoveServerBuildRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminRemoveServerBuildRequest Request;
    PlayFab::UPlayFabAdminAPI::FRemoveServerBuildDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FRemoveServerBuildResult& Result);
};