// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminGetPlayedTitleList.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminGetPlayedTitleList::UPFAdminGetPlayedTitleList(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetPlayedTitleListDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminGetPlayedTitleList* UPFAdminGetPlayedTitleList::GetPlayedTitleList(class APlayerController* PlayerController, const FBPAdminGetPlayedTitleListRequest& InGetPlayedTitleListRequest)
{
    UPFAdminGetPlayedTitleList* Proxy = NewObject<UPFAdminGetPlayedTitleList>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayedTitleListRequest;
    
    return Proxy;
}

void UPFAdminGetPlayedTitleList::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->GetPlayedTitleList(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminGetPlayedTitleList::OnSuccessCallback(const PlayFab::AdminModels::FGetPlayedTitleListResult& Result)
{
    FBPAdminGetPlayedTitleListResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
