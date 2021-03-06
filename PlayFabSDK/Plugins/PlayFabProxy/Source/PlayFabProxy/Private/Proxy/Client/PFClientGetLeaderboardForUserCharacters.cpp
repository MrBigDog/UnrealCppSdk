// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetLeaderboardForUserCharacters.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetLeaderboardForUserCharacters::UPFClientGetLeaderboardForUserCharacters(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetLeaderboardForUserCharactersDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetLeaderboardForUserCharacters* UPFClientGetLeaderboardForUserCharacters::GetLeaderboardForUserCharacters(class APlayerController* PlayerController, const FBPClientGetLeaderboardForUsersCharactersRequest& InGetLeaderboardForUsersCharactersRequest)
{
    UPFClientGetLeaderboardForUserCharacters* Proxy = NewObject<UPFClientGetLeaderboardForUserCharacters>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetLeaderboardForUsersCharactersRequest;
    
    return Proxy;
}

void UPFClientGetLeaderboardForUserCharacters::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if (ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetLeaderboardForUserCharacters(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFClientGetLeaderboardForUserCharacters::OnSuccessCallback(const PlayFab::ClientModels::FGetLeaderboardForUsersCharactersResult& Result)
{
    FBPClientGetLeaderboardForUsersCharactersResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
