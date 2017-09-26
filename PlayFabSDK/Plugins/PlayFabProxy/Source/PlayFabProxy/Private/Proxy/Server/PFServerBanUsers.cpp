// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerBanUsers.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerBanUsers::UPFServerBanUsers(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FBanUsersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerBanUsers* UPFServerBanUsers::BanUsers(class APlayerController* PlayerController, const FBPServerBanUsersRequest& InBanUsersRequest)
{
    UPFServerBanUsers* Proxy = NewObject<UPFServerBanUsers>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InBanUsersRequest;
    
    return Proxy;
}

void UPFServerBanUsers::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->BanUsers(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerBanUsers::OnSuccessCallback(const PlayFab::ServerModels::FBanUsersResult& Result)
{
    FBPServerBanUsersResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
