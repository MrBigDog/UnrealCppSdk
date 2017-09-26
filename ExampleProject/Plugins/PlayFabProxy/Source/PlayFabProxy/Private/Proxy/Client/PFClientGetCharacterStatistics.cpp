// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetCharacterStatistics.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetCharacterStatistics::UPFClientGetCharacterStatistics(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetCharacterStatisticsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetCharacterStatistics* UPFClientGetCharacterStatistics::GetCharacterStatistics(class APlayerController* PlayerController, const FBPClientGetCharacterStatisticsRequest& InGetCharacterStatisticsRequest)
{
    UPFClientGetCharacterStatistics* Proxy = NewObject<UPFClientGetCharacterStatistics>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetCharacterStatisticsRequest;
    
    return Proxy;
}

void UPFClientGetCharacterStatistics::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetCharacterStatistics(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetCharacterStatistics::OnSuccessCallback(const PlayFab::ClientModels::FGetCharacterStatisticsResult& Result)
{
    FBPClientGetCharacterStatisticsResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
