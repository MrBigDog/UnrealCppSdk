// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientPayForPurchase.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientPayForPurchase::UPFClientPayForPurchase(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FPayForPurchaseDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientPayForPurchase* UPFClientPayForPurchase::PayForPurchase(class APlayerController* PlayerController, const FBPClientPayForPurchaseRequest& InPayForPurchaseRequest)
{
    UPFClientPayForPurchase* Proxy = NewObject<UPFClientPayForPurchase>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InPayForPurchaseRequest;
    
    return Proxy;
}

void UPFClientPayForPurchase::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->PayForPurchase(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientPayForPurchase::OnSuccessCallback(const PlayFab::ClientModels::FPayForPurchaseResult& Result)
{
    FBPClientPayForPurchaseResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
