// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminGetUserAccountInfo.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminGetUserAccountInfo::UPFAdminGetUserAccountInfo(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetUserAccountInfoDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminGetUserAccountInfo* UPFAdminGetUserAccountInfo::GetUserAccountInfo(class APlayerController* PlayerController, const FBPAdminLookupUserAccountInfoRequest& InLookupUserAccountInfoRequest)
{
    UPFAdminGetUserAccountInfo* Proxy = NewObject<UPFAdminGetUserAccountInfo>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InLookupUserAccountInfoRequest;
    
    return Proxy;
}

void UPFAdminGetUserAccountInfo::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->GetUserAccountInfo(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminGetUserAccountInfo::OnSuccessCallback(const PlayFab::AdminModels::FLookupUserAccountInfoResult& Result)
{
    FBPAdminLookupUserAccountInfoResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
