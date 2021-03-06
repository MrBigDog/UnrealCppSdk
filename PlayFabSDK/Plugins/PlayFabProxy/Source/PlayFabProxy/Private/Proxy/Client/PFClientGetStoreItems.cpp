// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetStoreItems.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetStoreItems::UPFClientGetStoreItems(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetStoreItemsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetStoreItems* UPFClientGetStoreItems::GetStoreItems(class APlayerController* PlayerController, const FBPClientGetStoreItemsRequest& InGetStoreItemsRequest)
{
    UPFClientGetStoreItems* Proxy = NewObject<UPFClientGetStoreItems>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetStoreItemsRequest;
    
    return Proxy;
}

void UPFClientGetStoreItems::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetStoreItems(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientGetStoreItems::OnSuccessCallback(const PlayFab::ClientModels::FGetStoreItemsResult& Result)
{
    FBPClientGetStoreItemsResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
