// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetPlayFabIDsFromFacebookIDs.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetPlayFabIDsFromFacebookIDs::UPFClientGetPlayFabIDsFromFacebookIDs(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayFabIDsFromFacebookIDsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetPlayFabIDsFromFacebookIDs* UPFClientGetPlayFabIDsFromFacebookIDs::GetPlayFabIDsFromFacebookIDs(class APlayerController* PlayerController, const FBPClientGetPlayFabIDsFromFacebookIDsRequest& InGetPlayFabIDsFromFacebookIDsRequest)
{
    UPFClientGetPlayFabIDsFromFacebookIDs* Proxy = NewObject<UPFClientGetPlayFabIDsFromFacebookIDs>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayFabIDsFromFacebookIDsRequest;
    
    return Proxy;
}

void UPFClientGetPlayFabIDsFromFacebookIDs::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetPlayFabIDsFromFacebookIDs(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetPlayFabIDsFromFacebookIDs::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayFabIDsFromFacebookIDsResult& Result)
{
    FBPClientGetPlayFabIDsFromFacebookIDsResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
