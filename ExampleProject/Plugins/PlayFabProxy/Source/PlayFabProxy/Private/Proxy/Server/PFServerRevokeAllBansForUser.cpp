// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerRevokeAllBansForUser.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerRevokeAllBansForUser::UPFServerRevokeAllBansForUser(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FRevokeAllBansForUserDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerRevokeAllBansForUser* UPFServerRevokeAllBansForUser::RevokeAllBansForUser(class APlayerController* PlayerController, const FBPServerRevokeAllBansForUserRequest& InRevokeAllBansForUserRequest)
{
    UPFServerRevokeAllBansForUser* Proxy = NewObject<UPFServerRevokeAllBansForUser>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InRevokeAllBansForUserRequest;
    
    return Proxy;
}

void UPFServerRevokeAllBansForUser::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->RevokeAllBansForUser(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerRevokeAllBansForUser::OnSuccessCallback(const PlayFab::ServerModels::FRevokeAllBansForUserResult& Result)
{
    FBPServerRevokeAllBansForUserResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
