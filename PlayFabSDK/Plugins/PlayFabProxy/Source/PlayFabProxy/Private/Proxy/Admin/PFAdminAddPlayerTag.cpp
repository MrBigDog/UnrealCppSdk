// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminAddPlayerTag.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminAddPlayerTag::UPFAdminAddPlayerTag(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FAddPlayerTagDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminAddPlayerTag* UPFAdminAddPlayerTag::AddPlayerTag(class APlayerController* PlayerController, const FBPAdminAddPlayerTagRequest& InAddPlayerTagRequest)
{
    UPFAdminAddPlayerTag* Proxy = NewObject<UPFAdminAddPlayerTag>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InAddPlayerTagRequest;
    
    return Proxy;
}

void UPFAdminAddPlayerTag::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->AddPlayerTag(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminAddPlayerTag::OnSuccessCallback(const PlayFab::AdminModels::FAddPlayerTagResult& Result)
{
    OnSuccess.Broadcast();
}
