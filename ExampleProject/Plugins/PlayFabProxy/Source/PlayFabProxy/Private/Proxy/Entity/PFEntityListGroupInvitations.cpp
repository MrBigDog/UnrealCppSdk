// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFEntityListGroupInvitations.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFEntityListGroupInvitations::UPFEntityListGroupInvitations(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabEntityAPI::FListGroupInvitationsDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFEntityListGroupInvitations* UPFEntityListGroupInvitations::ListGroupInvitations(class APlayerController* PlayerController, const FBPEntityListGroupInvitationsRequest& InListGroupInvitationsRequest)
{
    UPFEntityListGroupInvitations* Proxy = NewObject<UPFEntityListGroupInvitations>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InListGroupInvitationsRequest;
    
    return Proxy;
}

void UPFEntityListGroupInvitations::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabEntityPtr EntityAPI = IPlayFabModuleInterface::Get().GetEntityAPI();

    bool CallResult = false;

    if (EntityAPI.IsValid())
    {
        CallResult = EntityAPI->ListGroupInvitations(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFEntityListGroupInvitations::OnSuccessCallback(const PlayFab::EntityModels::FListGroupInvitationsResponse& Result)
{
    FBPEntityListGroupInvitationsResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
