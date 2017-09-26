// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientAddFriend.generated.h"

UCLASS(MinimalAPI)
class UPFClientAddFriend : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientAddFriendResultDelegate OnSuccess;

    // Adds the PlayFab user, based upon a match against a supplied unique identifier, to the friend list of the local user. At least one of FriendPlayFabId,FriendUsername,FriendEmail, or FriendTitleDisplayName should be initialized.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Friend List Management")
        static UPFClientAddFriend* AddFriend(class APlayerController* PlayerController, const FBPClientAddFriendRequest& InAddFriendRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientAddFriendRequest Request;
    PlayFab::UPlayFabClientAPI::FAddFriendDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FAddFriendResult& Result);
};
