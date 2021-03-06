// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientLoginWithPlayFab.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientLoginWithPlayFab::UPFClientLoginWithPlayFab(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FLoginWithPlayFabDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientLoginWithPlayFab* UPFClientLoginWithPlayFab::LoginWithPlayFab(class APlayerController* PlayerController, const FBPClientLoginWithPlayFabRequest& InLoginWithPlayFabRequest)
{
    UPFClientLoginWithPlayFab* Proxy = NewObject<UPFClientLoginWithPlayFab>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InLoginWithPlayFabRequest;
    
    return Proxy;
}

void UPFClientLoginWithPlayFab::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->LoginWithPlayFab(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientLoginWithPlayFab::OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result)
{
    FBPClientLoginResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
