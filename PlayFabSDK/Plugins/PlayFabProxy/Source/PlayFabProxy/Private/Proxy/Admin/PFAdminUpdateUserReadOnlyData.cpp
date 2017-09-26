// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminUpdateUserReadOnlyData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminUpdateUserReadOnlyData::UPFAdminUpdateUserReadOnlyData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FUpdateUserReadOnlyDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminUpdateUserReadOnlyData* UPFAdminUpdateUserReadOnlyData::UpdateUserReadOnlyData(class APlayerController* PlayerController, const FBPAdminUpdateUserDataRequest& InUpdateUserDataRequest)
{
    UPFAdminUpdateUserReadOnlyData* Proxy = NewObject<UPFAdminUpdateUserReadOnlyData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateUserDataRequest;
    
    return Proxy;
}

void UPFAdminUpdateUserReadOnlyData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->UpdateUserReadOnlyData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminUpdateUserReadOnlyData::OnSuccessCallback(const PlayFab::AdminModels::FUpdateUserDataResult& Result)
{
    FBPAdminUpdateUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
