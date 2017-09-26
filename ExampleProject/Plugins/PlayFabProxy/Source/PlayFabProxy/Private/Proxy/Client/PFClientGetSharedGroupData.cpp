// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetSharedGroupData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetSharedGroupData::UPFClientGetSharedGroupData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetSharedGroupDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetSharedGroupData* UPFClientGetSharedGroupData::GetSharedGroupData(class APlayerController* PlayerController, const FBPClientGetSharedGroupDataRequest& InGetSharedGroupDataRequest)
{
    UPFClientGetSharedGroupData* Proxy = NewObject<UPFClientGetSharedGroupData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetSharedGroupDataRequest;
    
    return Proxy;
}

void UPFClientGetSharedGroupData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetSharedGroupData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetSharedGroupData::OnSuccessCallback(const PlayFab::ClientModels::FGetSharedGroupDataResult& Result)
{
    FBPClientGetSharedGroupDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
