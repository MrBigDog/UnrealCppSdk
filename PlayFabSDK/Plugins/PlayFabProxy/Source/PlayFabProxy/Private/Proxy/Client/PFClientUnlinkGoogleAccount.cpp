// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientUnlinkGoogleAccount.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientUnlinkGoogleAccount::UPFClientUnlinkGoogleAccount(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FUnlinkGoogleAccountDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientUnlinkGoogleAccount* UPFClientUnlinkGoogleAccount::UnlinkGoogleAccount(class APlayerController* PlayerController)
{
    UPFClientUnlinkGoogleAccount* Proxy = NewObject<UPFClientUnlinkGoogleAccount>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    
    return Proxy;
}

void UPFClientUnlinkGoogleAccount::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->UnlinkGoogleAccount(SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientUnlinkGoogleAccount::OnSuccessCallback(const PlayFab::ClientModels::FUnlinkGoogleAccountResult& Result)
{
    OnSuccess.Broadcast();
}
