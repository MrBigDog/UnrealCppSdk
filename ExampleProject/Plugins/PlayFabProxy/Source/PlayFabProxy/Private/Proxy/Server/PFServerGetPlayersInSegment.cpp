// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetPlayersInSegment.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetPlayersInSegment::UPFServerGetPlayersInSegment(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetPlayersInSegmentDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetPlayersInSegment* UPFServerGetPlayersInSegment::GetPlayersInSegment(class APlayerController* PlayerController, const FBPServerGetPlayersInSegmentRequest& InGetPlayersInSegmentRequest)
{
    UPFServerGetPlayersInSegment* Proxy = NewObject<UPFServerGetPlayersInSegment>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayersInSegmentRequest;
    
    return Proxy;
}

void UPFServerGetPlayersInSegment::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetPlayersInSegment(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerGetPlayersInSegment::OnSuccessCallback(const PlayFab::ServerModels::FGetPlayersInSegmentResult& Result)
{
    FBPServerGetPlayersInSegmentResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
