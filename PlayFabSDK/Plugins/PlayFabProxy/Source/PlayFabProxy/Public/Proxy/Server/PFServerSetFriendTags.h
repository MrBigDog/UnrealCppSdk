// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabServerAPI.h"
#include "Core/PlayFabServerDataModels.h"
#include "Proxy/PlayFabServerBPDataModels.h"
#include "PFServerSetFriendTags.generated.h"

UCLASS(MinimalAPI)
class UPFServerSetFriendTags : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Updates the tag list for a specified user in the friend list of another user
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Server|Friend List Management")
        static UPFServerSetFriendTags* SetFriendTags(class APlayerController* PlayerController, const FBPServerSetFriendTagsRequest& InSetFriendTagsRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPServerSetFriendTagsRequest Request;
    PlayFab::UPlayFabServerAPI::FSetFriendTagsDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ServerModels::FEmptyResult& Result);
};
