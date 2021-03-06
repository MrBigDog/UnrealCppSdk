// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminSetTitleData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminSetTitleData::UPFAdminSetTitleData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FSetTitleDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminSetTitleData* UPFAdminSetTitleData::SetTitleData(class APlayerController* PlayerController, const FBPAdminSetTitleDataRequest& InSetTitleDataRequest)
{
    UPFAdminSetTitleData* Proxy = NewObject<UPFAdminSetTitleData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InSetTitleDataRequest;
    
    return Proxy;
}

void UPFAdminSetTitleData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if (AdminAPI.IsValid())
    {
        CallResult = AdminAPI->SetTitleData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFAdminSetTitleData::OnSuccessCallback(const PlayFab::AdminModels::FSetTitleDataResult& Result)
{
    OnSuccess.Broadcast();
}
