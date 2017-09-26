// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientLoginWithSteam.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientLoginWithSteam::UPFClientLoginWithSteam(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FLoginWithSteamDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientLoginWithSteam* UPFClientLoginWithSteam::LoginWithSteam(class APlayerController* PlayerController, const FBPClientLoginWithSteamRequest& InLoginWithSteamRequest)
{
    UPFClientLoginWithSteam* Proxy = NewObject<UPFClientLoginWithSteam>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InLoginWithSteamRequest;
    
    return Proxy;
}

void UPFClientLoginWithSteam::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->LoginWithSteam(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientLoginWithSteam::OnSuccessCallback(const PlayFab::ClientModels::FLoginResult& Result)
{
    FBPClientLoginResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
