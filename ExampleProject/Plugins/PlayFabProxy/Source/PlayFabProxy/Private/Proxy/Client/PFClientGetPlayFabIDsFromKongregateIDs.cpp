// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetPlayFabIDsFromKongregateIDs.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetPlayFabIDsFromKongregateIDs::UPFClientGetPlayFabIDsFromKongregateIDs(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayFabIDsFromKongregateIDsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetPlayFabIDsFromKongregateIDs* UPFClientGetPlayFabIDsFromKongregateIDs::GetPlayFabIDsFromKongregateIDs(class APlayerController* PlayerController, const FBPClientGetPlayFabIDsFromKongregateIDsRequest& InGetPlayFabIDsFromKongregateIDsRequest)
{
    UPFClientGetPlayFabIDsFromKongregateIDs* Proxy = NewObject<UPFClientGetPlayFabIDsFromKongregateIDs>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayFabIDsFromKongregateIDsRequest;
    
    return Proxy;
}

void UPFClientGetPlayFabIDsFromKongregateIDs::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetPlayFabIDsFromKongregateIDs(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetPlayFabIDsFromKongregateIDs::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayFabIDsFromKongregateIDsResult& Result)
{
    FBPClientGetPlayFabIDsFromKongregateIDsResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
