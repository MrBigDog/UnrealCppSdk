// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminUpdateCatalogItems.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminUpdateCatalogItems::UPFAdminUpdateCatalogItems(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdateCatalogItemsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminUpdateCatalogItems* UPFAdminUpdateCatalogItems::UpdateCatalogItems(class APlayerController* PlayerController, const FBPAdminUpdateCatalogItemsRequest& InUpdateCatalogItemsRequest)
{
    UPFAdminUpdateCatalogItems* Proxy = NewObject<UPFAdminUpdateCatalogItems>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateCatalogItemsRequest;
    
    return Proxy;
}

void UPFAdminUpdateCatalogItems::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->UpdateCatalogItems(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminUpdateCatalogItems::OnSuccessCallback(const PlayFab::AdminModels::FUpdateCatalogItemsResult& Result)
{
    OnSuccess.Broadcast();
}
