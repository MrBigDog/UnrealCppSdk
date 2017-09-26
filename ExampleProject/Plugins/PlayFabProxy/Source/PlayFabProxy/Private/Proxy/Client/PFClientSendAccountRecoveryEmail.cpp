// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientSendAccountRecoveryEmail.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientSendAccountRecoveryEmail::UPFClientSendAccountRecoveryEmail(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FSendAccountRecoveryEmailDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientSendAccountRecoveryEmail* UPFClientSendAccountRecoveryEmail::SendAccountRecoveryEmail(class APlayerController* PlayerController, const FBPClientSendAccountRecoveryEmailRequest& InSendAccountRecoveryEmailRequest)
{
    UPFClientSendAccountRecoveryEmail* Proxy = NewObject<UPFClientSendAccountRecoveryEmail>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InSendAccountRecoveryEmailRequest;
    
    return Proxy;
}

void UPFClientSendAccountRecoveryEmail::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->SendAccountRecoveryEmail(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientSendAccountRecoveryEmail::OnSuccessCallback(const PlayFab::ClientModels::FSendAccountRecoveryEmailResult& Result)
{
    OnSuccess.Broadcast();
}
