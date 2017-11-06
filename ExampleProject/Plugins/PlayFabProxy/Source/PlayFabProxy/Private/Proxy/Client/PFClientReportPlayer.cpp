// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientReportPlayer.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientReportPlayer::UPFClientReportPlayer(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FReportPlayerDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientReportPlayer* UPFClientReportPlayer::ReportPlayer(class APlayerController* PlayerController, const FBPClientReportPlayerClientRequest& InReportPlayerClientRequest)
{
    UPFClientReportPlayer* Proxy = NewObject<UPFClientReportPlayer>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InReportPlayerClientRequest;
    
    return Proxy;
}

void UPFClientReportPlayer::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->ReportPlayer(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientReportPlayer::OnSuccessCallback(const PlayFab::ClientModels::FReportPlayerClientResult& Result)
{
    FBPClientReportPlayerClientResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}