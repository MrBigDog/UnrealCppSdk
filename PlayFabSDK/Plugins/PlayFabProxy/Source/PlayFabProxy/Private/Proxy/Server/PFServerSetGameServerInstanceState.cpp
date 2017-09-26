// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerSetGameServerInstanceState.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerSetGameServerInstanceState::UPFServerSetGameServerInstanceState(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FSetGameServerInstanceStateDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerSetGameServerInstanceState* UPFServerSetGameServerInstanceState::SetGameServerInstanceState(class APlayerController* PlayerController, const FBPServerSetGameServerInstanceStateRequest& InSetGameServerInstanceStateRequest)
{
    UPFServerSetGameServerInstanceState* Proxy = NewObject<UPFServerSetGameServerInstanceState>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InSetGameServerInstanceStateRequest;
    
    return Proxy;
}

void UPFServerSetGameServerInstanceState::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->SetGameServerInstanceState(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerSetGameServerInstanceState::OnSuccessCallback(const PlayFab::ServerModels::FSetGameServerInstanceStateResult& Result)
{
    OnSuccess.Broadcast();
}
