// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminDeleteMasterPlayerAccount.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminDeleteMasterPlayerAccount::UPFAdminDeleteMasterPlayerAccount(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FDeleteMasterPlayerAccountDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminDeleteMasterPlayerAccount* UPFAdminDeleteMasterPlayerAccount::DeleteMasterPlayerAccount(class APlayerController* PlayerController, const FBPAdminDeleteMasterPlayerAccountRequest& InDeleteMasterPlayerAccountRequest)
{
    UPFAdminDeleteMasterPlayerAccount* Proxy = NewObject<UPFAdminDeleteMasterPlayerAccount>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InDeleteMasterPlayerAccountRequest;
    
    return Proxy;
}

void UPFAdminDeleteMasterPlayerAccount::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->DeleteMasterPlayerAccount(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminDeleteMasterPlayerAccount::OnSuccessCallback(const PlayFab::AdminModels::FDeleteMasterPlayerAccountResult& Result)
{
    FBPAdminDeleteMasterPlayerAccountResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}