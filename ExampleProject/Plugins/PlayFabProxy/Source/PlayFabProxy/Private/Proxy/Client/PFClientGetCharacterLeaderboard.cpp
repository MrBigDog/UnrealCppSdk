// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetCharacterLeaderboard.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetCharacterLeaderboard::UPFClientGetCharacterLeaderboard(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetCharacterLeaderboardDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetCharacterLeaderboard* UPFClientGetCharacterLeaderboard::GetCharacterLeaderboard(class APlayerController* PlayerController, const FBPClientGetCharacterLeaderboardRequest& InGetCharacterLeaderboardRequest)
{
    UPFClientGetCharacterLeaderboard* Proxy = NewObject<UPFClientGetCharacterLeaderboard>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetCharacterLeaderboardRequest;
    
    return Proxy;
}

void UPFClientGetCharacterLeaderboard::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetCharacterLeaderboard(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetCharacterLeaderboard::OnSuccessCallback(const PlayFab::ClientModels::FGetCharacterLeaderboardResult& Result)
{
    FBPClientGetCharacterLeaderboardResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}