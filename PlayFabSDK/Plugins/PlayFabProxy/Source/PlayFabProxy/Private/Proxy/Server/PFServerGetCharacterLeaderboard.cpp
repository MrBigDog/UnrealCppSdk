// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetCharacterLeaderboard.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetCharacterLeaderboard::UPFServerGetCharacterLeaderboard(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetCharacterLeaderboardDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetCharacterLeaderboard* UPFServerGetCharacterLeaderboard::GetCharacterLeaderboard(class APlayerController* PlayerController, const FBPServerGetCharacterLeaderboardRequest& InGetCharacterLeaderboardRequest)
{
    UPFServerGetCharacterLeaderboard* Proxy = NewObject<UPFServerGetCharacterLeaderboard>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetCharacterLeaderboardRequest;
    
    return Proxy;
}

void UPFServerGetCharacterLeaderboard::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetCharacterLeaderboard(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerGetCharacterLeaderboard::OnSuccessCallback(const PlayFab::ServerModels::FGetCharacterLeaderboardResult& Result)
{
    FBPServerGetCharacterLeaderboardResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}