// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientRegisterPlayFabUser.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientRegisterPlayFabUser::UPFClientRegisterPlayFabUser(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FRegisterPlayFabUserDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientRegisterPlayFabUser* UPFClientRegisterPlayFabUser::RegisterPlayFabUser(class APlayerController* PlayerController, const FBPClientRegisterPlayFabUserRequest& InRegisterPlayFabUserRequest)
{
    UPFClientRegisterPlayFabUser* Proxy = NewObject<UPFClientRegisterPlayFabUser>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRegisterPlayFabUserRequest;
    
    return Proxy;
}

void UPFClientRegisterPlayFabUser::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->RegisterPlayFabUser(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientRegisterPlayFabUser::OnSuccessCallback(const PlayFab::ClientModels::FRegisterPlayFabUserResult& Result)
{
    FBPClientRegisterPlayFabUserResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
