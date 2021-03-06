// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFEntityGetGroup.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFEntityGetGroup::UPFEntityGetGroup(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabEntityAPI::FGetGroupDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFEntityGetGroup* UPFEntityGetGroup::GetGroup(class APlayerController* PlayerController, const FBPEntityGetGroupRequest& InGetGroupRequest)
{
    UPFEntityGetGroup* Proxy = NewObject<UPFEntityGetGroup>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetGroupRequest;
    
    return Proxy;
}

void UPFEntityGetGroup::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabEntityPtr EntityAPI = IPlayFabModuleInterface::Get().GetEntityAPI();

    bool CallResult = false;

    if (EntityAPI.IsValid())
    {
        CallResult = EntityAPI->GetGroup(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFEntityGetGroup::OnSuccessCallback(const PlayFab::EntityModels::FGetGroupResponse& Result)
{
    FBPEntityGetGroupResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
