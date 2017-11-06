// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetSharedGroupData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetSharedGroupData::UPFServerGetSharedGroupData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetSharedGroupDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetSharedGroupData* UPFServerGetSharedGroupData::GetSharedGroupData(class APlayerController* PlayerController, const FBPServerGetSharedGroupDataRequest& InGetSharedGroupDataRequest)
{
    UPFServerGetSharedGroupData* Proxy = NewObject<UPFServerGetSharedGroupData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetSharedGroupDataRequest;
    
    return Proxy;
}

void UPFServerGetSharedGroupData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetSharedGroupData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerGetSharedGroupData::OnSuccessCallback(const PlayFab::ServerModels::FGetSharedGroupDataResult& Result)
{
    FBPServerGetSharedGroupDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}