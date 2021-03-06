// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetUserInventory.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetUserInventory::UPFServerGetUserInventory(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetUserInventoryDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetUserInventory* UPFServerGetUserInventory::GetUserInventory(class APlayerController* PlayerController, const FBPServerGetUserInventoryRequest& InGetUserInventoryRequest)
{
    UPFServerGetUserInventory* Proxy = NewObject<UPFServerGetUserInventory>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetUserInventoryRequest;
    
    return Proxy;
}

void UPFServerGetUserInventory::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetUserInventory(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerGetUserInventory::OnSuccessCallback(const PlayFab::ServerModels::FGetUserInventoryResult& Result)
{
    FBPServerGetUserInventoryResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
