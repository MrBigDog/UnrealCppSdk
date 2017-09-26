// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminCreatePlayerSharedSecret.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminCreatePlayerSharedSecret::UPFAdminCreatePlayerSharedSecret(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FCreatePlayerSharedSecretDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminCreatePlayerSharedSecret* UPFAdminCreatePlayerSharedSecret::CreatePlayerSharedSecret(class APlayerController* PlayerController, const FBPAdminCreatePlayerSharedSecretRequest& InCreatePlayerSharedSecretRequest)
{
    UPFAdminCreatePlayerSharedSecret* Proxy = NewObject<UPFAdminCreatePlayerSharedSecret>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InCreatePlayerSharedSecretRequest;
    
    return Proxy;
}

void UPFAdminCreatePlayerSharedSecret::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->CreatePlayerSharedSecret(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminCreatePlayerSharedSecret::OnSuccessCallback(const PlayFab::AdminModels::FCreatePlayerSharedSecretResult& Result)
{
    FBPAdminCreatePlayerSharedSecretResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
