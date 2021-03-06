// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFEntityListMembershipOpportunities.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFEntityListMembershipOpportunities::UPFEntityListMembershipOpportunities(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabEntityAPI::FListMembershipOpportunitiesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFEntityListMembershipOpportunities* UPFEntityListMembershipOpportunities::ListMembershipOpportunities(class APlayerController* PlayerController, const FBPEntityListMembershipOpportunitiesRequest& InListMembershipOpportunitiesRequest)
{
    UPFEntityListMembershipOpportunities* Proxy = NewObject<UPFEntityListMembershipOpportunities>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InListMembershipOpportunitiesRequest;
    
    return Proxy;
}

void UPFEntityListMembershipOpportunities::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabEntityPtr EntityAPI = IPlayFabModuleInterface::Get().GetEntityAPI();

    bool CallResult = false;

    if (EntityAPI.IsValid())
    {
        CallResult = EntityAPI->ListMembershipOpportunities(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFEntityListMembershipOpportunities::OnSuccessCallback(const PlayFab::EntityModels::FListMembershipOpportunitiesResponse& Result)
{
    FBPEntityListMembershipOpportunitiesResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
