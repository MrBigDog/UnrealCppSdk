// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetFriendsList.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetFriendsList::UPFClientGetFriendsList(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetFriendsListDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetFriendsList* UPFClientGetFriendsList::GetFriendsList(class APlayerController* PlayerController, const FBPClientGetFriendsListRequest& InGetFriendsListRequest)
{
    UPFClientGetFriendsList* Proxy = NewObject<UPFClientGetFriendsList>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetFriendsListRequest;
    
    return Proxy;
}

void UPFClientGetFriendsList::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetFriendsList(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetFriendsList::OnSuccessCallback(const PlayFab::ClientModels::FGetFriendsListResult& Result)
{
    FBPClientGetFriendsListResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
