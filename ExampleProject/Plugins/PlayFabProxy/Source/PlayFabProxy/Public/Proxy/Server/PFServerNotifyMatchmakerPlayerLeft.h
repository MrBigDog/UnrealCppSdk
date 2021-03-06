// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerNotifyMatchmakerPlayerLeft.generated.h"

UCLASS(MinimalAPI)
class UPFServerNotifyMatchmakerPlayerLeft : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPServerNotifyMatchmakerPlayerLeftResultDelegate OnSuccess;

    // Informs the PlayFab match-making service that the user specified has left the Game Server Instance
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Matchmaking")
        static UPFServerNotifyMatchmakerPlayerLeft* NotifyMatchmakerPlayerLeft(class APlayerController* PlayerController, const FBPServerNotifyMatchmakerPlayerLeftRequest& InNotifyMatchmakerPlayerLeftRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerNotifyMatchmakerPlayerLeftRequest Request;
    PlayFab::UPlayFabServerAPI::FNotifyMatchmakerPlayerLeftDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FNotifyMatchmakerPlayerLeftResult& Result);
};
