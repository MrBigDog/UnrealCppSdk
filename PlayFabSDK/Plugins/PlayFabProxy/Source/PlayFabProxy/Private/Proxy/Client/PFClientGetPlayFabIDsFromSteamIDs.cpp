// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetPlayFabIDsFromSteamIDs.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetPlayFabIDsFromSteamIDs::UPFClientGetPlayFabIDsFromSteamIDs(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayFabIDsFromSteamIDsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetPlayFabIDsFromSteamIDs* UPFClientGetPlayFabIDsFromSteamIDs::GetPlayFabIDsFromSteamIDs(class APlayerController* PlayerController, const FBPClientGetPlayFabIDsFromSteamIDsRequest& InGetPlayFabIDsFromSteamIDsRequest)
{
    UPFClientGetPlayFabIDsFromSteamIDs* Proxy = NewObject<UPFClientGetPlayFabIDsFromSteamIDs>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayFabIDsFromSteamIDsRequest;
    
    return Proxy;
}

void UPFClientGetPlayFabIDsFromSteamIDs::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetPlayFabIDsFromSteamIDs(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetPlayFabIDsFromSteamIDs::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayFabIDsFromSteamIDsResult& Result)
{
    FBPClientGetPlayFabIDsFromSteamIDsResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
