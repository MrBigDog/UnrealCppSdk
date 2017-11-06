// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerNotifyMatchmakerPlayerLeft.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerNotifyMatchmakerPlayerLeft::UPFServerNotifyMatchmakerPlayerLeft(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FNotifyMatchmakerPlayerLeftDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerNotifyMatchmakerPlayerLeft* UPFServerNotifyMatchmakerPlayerLeft::NotifyMatchmakerPlayerLeft(class APlayerController* PlayerController, const FBPServerNotifyMatchmakerPlayerLeftRequest& InNotifyMatchmakerPlayerLeftRequest)
{
    UPFServerNotifyMatchmakerPlayerLeft* Proxy = NewObject<UPFServerNotifyMatchmakerPlayerLeft>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InNotifyMatchmakerPlayerLeftRequest;
    
    return Proxy;
}

void UPFServerNotifyMatchmakerPlayerLeft::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->NotifyMatchmakerPlayerLeft(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerNotifyMatchmakerPlayerLeft::OnSuccessCallback(const PlayFab::ServerModels::FNotifyMatchmakerPlayerLeftResult& Result)
{
    FBPServerNotifyMatchmakerPlayerLeftResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}