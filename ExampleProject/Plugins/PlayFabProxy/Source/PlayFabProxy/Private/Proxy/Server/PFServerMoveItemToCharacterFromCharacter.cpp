// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerMoveItemToCharacterFromCharacter.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerMoveItemToCharacterFromCharacter::UPFServerMoveItemToCharacterFromCharacter(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FMoveItemToCharacterFromCharacterDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerMoveItemToCharacterFromCharacter* UPFServerMoveItemToCharacterFromCharacter::MoveItemToCharacterFromCharacter(class APlayerController* PlayerController, const FBPServerMoveItemToCharacterFromCharacterRequest& InMoveItemToCharacterFromCharacterRequest)
{
    UPFServerMoveItemToCharacterFromCharacter* Proxy = NewObject<UPFServerMoveItemToCharacterFromCharacter>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InMoveItemToCharacterFromCharacterRequest;
    
    return Proxy;
}

void UPFServerMoveItemToCharacterFromCharacter::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->MoveItemToCharacterFromCharacter(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerMoveItemToCharacterFromCharacter::OnSuccessCallback(const PlayFab::ServerModels::FMoveItemToCharacterFromCharacterResult& Result)
{
    OnSuccess.Broadcast();
}
