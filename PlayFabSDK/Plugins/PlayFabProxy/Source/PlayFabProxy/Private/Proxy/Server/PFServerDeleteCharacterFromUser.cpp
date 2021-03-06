// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerDeleteCharacterFromUser.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerDeleteCharacterFromUser::UPFServerDeleteCharacterFromUser(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FDeleteCharacterFromUserDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerDeleteCharacterFromUser* UPFServerDeleteCharacterFromUser::DeleteCharacterFromUser(class APlayerController* PlayerController, const FBPServerDeleteCharacterFromUserRequest& InDeleteCharacterFromUserRequest)
{
    UPFServerDeleteCharacterFromUser* Proxy = NewObject<UPFServerDeleteCharacterFromUser>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InDeleteCharacterFromUserRequest;
    
    return Proxy;
}

void UPFServerDeleteCharacterFromUser::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if (ServerAPI.IsValid())
    {
        CallResult = ServerAPI->DeleteCharacterFromUser(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFServerDeleteCharacterFromUser::OnSuccessCallback(const PlayFab::ServerModels::FDeleteCharacterFromUserResult& Result)
{
    OnSuccess.Broadcast();
}
