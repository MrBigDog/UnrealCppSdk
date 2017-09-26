// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerUpdateUserInternalData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerUpdateUserInternalData::UPFServerUpdateUserInternalData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FUpdateUserInternalDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerUpdateUserInternalData* UPFServerUpdateUserInternalData::UpdateUserInternalData(class APlayerController* PlayerController, const FBPServerUpdateUserInternalDataRequest& InUpdateUserInternalDataRequest)
{
    UPFServerUpdateUserInternalData* Proxy = NewObject<UPFServerUpdateUserInternalData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateUserInternalDataRequest;
    
    return Proxy;
}

void UPFServerUpdateUserInternalData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->UpdateUserInternalData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerUpdateUserInternalData::OnSuccessCallback(const PlayFab::ServerModels::FUpdateUserDataResult& Result)
{
    FBPServerUpdateUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
