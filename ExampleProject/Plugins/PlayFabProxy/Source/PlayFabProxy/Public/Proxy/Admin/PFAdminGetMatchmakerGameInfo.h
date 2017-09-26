// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetMatchmakerGameInfo.generated.h"

UCLASS(MinimalAPI)
class UPFAdminGetMatchmakerGameInfo : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminGetMatchmakerGameInfoResultDelegate OnSuccess;

    // Retrieves the details for a specific completed session, including links to standard out and standard error logs
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Matchmaking")
        static UPFAdminGetMatchmakerGameInfo* GetMatchmakerGameInfo(class APlayerController* PlayerController, const FBPAdminGetMatchmakerGameInfoRequest& InGetMatchmakerGameInfoRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminGetMatchmakerGameInfoRequest Request;
    PlayFab::UPlayFabAdminAPI::FGetMatchmakerGameInfoDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FGetMatchmakerGameInfoResult& Result);
};
