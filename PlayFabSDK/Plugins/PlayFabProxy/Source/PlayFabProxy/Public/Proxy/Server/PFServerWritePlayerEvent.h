// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerWritePlayerEvent.generated.h"

UCLASS(MinimalAPI)
class UPFServerWritePlayerEvent : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPServerWriteEventResponseDelegate OnSuccess;

    // Writes a player-based event into PlayStream.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Analytics")
        static UPFServerWritePlayerEvent* WritePlayerEvent(class APlayerController* PlayerController, const FBPServerWriteServerPlayerEventRequest& InWriteServerPlayerEventRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerWriteServerPlayerEventRequest Request;
    PlayFab::UPlayFabServerAPI::FWritePlayerEventDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FWriteEventResponse& Result);
};
