// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetCatalogItems.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetCatalogItems::UPFClientGetCatalogItems(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetCatalogItemsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetCatalogItems* UPFClientGetCatalogItems::GetCatalogItems(class APlayerController* PlayerController, const FBPClientGetCatalogItemsRequest& InGetCatalogItemsRequest)
{
    UPFClientGetCatalogItems* Proxy = NewObject<UPFClientGetCatalogItems>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetCatalogItemsRequest;
    
    return Proxy;
}

void UPFClientGetCatalogItems::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetCatalogItems(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientGetCatalogItems::OnSuccessCallback(const PlayFab::ClientModels::FGetCatalogItemsResult& Result)
{
    FBPClientGetCatalogItemsResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
