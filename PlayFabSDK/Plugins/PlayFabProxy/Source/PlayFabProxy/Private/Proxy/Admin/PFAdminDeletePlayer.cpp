// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminDeletePlayer.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminDeletePlayer::UPFAdminDeletePlayer(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FDeletePlayerDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminDeletePlayer* UPFAdminDeletePlayer::DeletePlayer(class APlayerController* PlayerController, const FBPAdminDeletePlayerRequest& InDeletePlayerRequest)
{
    UPFAdminDeletePlayer* Proxy = NewObject<UPFAdminDeletePlayer>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InDeletePlayerRequest;
    
    return Proxy;
}

void UPFAdminDeletePlayer::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->DeletePlayer(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminDeletePlayer::OnSuccessCallback(const PlayFab::AdminModels::FDeletePlayerResult& Result)
{
    OnSuccess.Broadcast();
}
