// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerMoveItemToCharacterFromUser.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerMoveItemToCharacterFromUser::UPFServerMoveItemToCharacterFromUser(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FMoveItemToCharacterFromUserDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerMoveItemToCharacterFromUser* UPFServerMoveItemToCharacterFromUser::MoveItemToCharacterFromUser(class APlayerController* PlayerController, const FBPServerMoveItemToCharacterFromUserRequest& InMoveItemToCharacterFromUserRequest)
{
    UPFServerMoveItemToCharacterFromUser* Proxy = NewObject<UPFServerMoveItemToCharacterFromUser>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InMoveItemToCharacterFromUserRequest;
    
    return Proxy;
}

void UPFServerMoveItemToCharacterFromUser::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->MoveItemToCharacterFromUser(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerMoveItemToCharacterFromUser::OnSuccessCallback(const PlayFab::ServerModels::FMoveItemToCharacterFromUserResult& Result)
{
    OnSuccess.Broadcast();
}