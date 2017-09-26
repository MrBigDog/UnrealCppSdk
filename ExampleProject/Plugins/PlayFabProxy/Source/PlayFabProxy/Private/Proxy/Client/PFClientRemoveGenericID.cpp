// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientRemoveGenericID.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientRemoveGenericID::UPFClientRemoveGenericID(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FRemoveGenericIDDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientRemoveGenericID* UPFClientRemoveGenericID::RemoveGenericID(class APlayerController* PlayerController, const FBPClientRemoveGenericIDRequest& InRemoveGenericIDRequest)
{
    UPFClientRemoveGenericID* Proxy = NewObject<UPFClientRemoveGenericID>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRemoveGenericIDRequest;
    
    return Proxy;
}

void UPFClientRemoveGenericID::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->RemoveGenericID(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientRemoveGenericID::OnSuccessCallback(const PlayFab::ClientModels::FRemoveGenericIDResult& Result)
{
    OnSuccess.Broadcast();
}
