// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetPlayerStatisticVersions.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetPlayerStatisticVersions::UPFClientGetPlayerStatisticVersions(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayerStatisticVersionsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetPlayerStatisticVersions* UPFClientGetPlayerStatisticVersions::GetPlayerStatisticVersions(class APlayerController* PlayerController, const FBPClientGetPlayerStatisticVersionsRequest& InGetPlayerStatisticVersionsRequest)
{
    UPFClientGetPlayerStatisticVersions* Proxy = NewObject<UPFClientGetPlayerStatisticVersions>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayerStatisticVersionsRequest;
    
    return Proxy;
}

void UPFClientGetPlayerStatisticVersions::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetPlayerStatisticVersions(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetPlayerStatisticVersions::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayerStatisticVersionsResult& Result)
{
    FBPClientGetPlayerStatisticVersionsResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}