// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminUpdateUserPublisherData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminUpdateUserPublisherData::UPFAdminUpdateUserPublisherData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdateUserPublisherDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminUpdateUserPublisherData* UPFAdminUpdateUserPublisherData::UpdateUserPublisherData(class APlayerController* PlayerController, const FBPAdminUpdateUserDataRequest& InUpdateUserDataRequest)
{
    UPFAdminUpdateUserPublisherData* Proxy = NewObject<UPFAdminUpdateUserPublisherData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateUserDataRequest;
    
    return Proxy;
}

void UPFAdminUpdateUserPublisherData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->UpdateUserPublisherData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminUpdateUserPublisherData::OnSuccessCallback(const PlayFab::AdminModels::FUpdateUserDataResult& Result)
{
    FBPAdminUpdateUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
