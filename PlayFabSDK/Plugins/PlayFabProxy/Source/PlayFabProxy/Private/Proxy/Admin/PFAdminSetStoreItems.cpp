// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminSetStoreItems.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminSetStoreItems::UPFAdminSetStoreItems(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FSetStoreItemsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminSetStoreItems* UPFAdminSetStoreItems::SetStoreItems(class APlayerController* PlayerController, const FBPAdminUpdateStoreItemsRequest& InUpdateStoreItemsRequest)
{
    UPFAdminSetStoreItems* Proxy = NewObject<UPFAdminSetStoreItems>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateStoreItemsRequest;
    
    return Proxy;
}

void UPFAdminSetStoreItems::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->SetStoreItems(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminSetStoreItems::OnSuccessCallback(const PlayFab::AdminModels::FUpdateStoreItemsResult& Result)
{
    OnSuccess.Broadcast();
}