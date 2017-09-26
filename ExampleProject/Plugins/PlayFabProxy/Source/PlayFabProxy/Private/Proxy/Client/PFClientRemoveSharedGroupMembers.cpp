// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientRemoveSharedGroupMembers.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientRemoveSharedGroupMembers::UPFClientRemoveSharedGroupMembers(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FRemoveSharedGroupMembersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientRemoveSharedGroupMembers* UPFClientRemoveSharedGroupMembers::RemoveSharedGroupMembers(class APlayerController* PlayerController, const FBPClientRemoveSharedGroupMembersRequest& InRemoveSharedGroupMembersRequest)
{
    UPFClientRemoveSharedGroupMembers* Proxy = NewObject<UPFClientRemoveSharedGroupMembers>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRemoveSharedGroupMembersRequest;
    
    return Proxy;
}

void UPFClientRemoveSharedGroupMembers::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->RemoveSharedGroupMembers(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientRemoveSharedGroupMembers::OnSuccessCallback(const PlayFab::ClientModels::FRemoveSharedGroupMembersResult& Result)
{
    OnSuccess.Broadcast();
}
