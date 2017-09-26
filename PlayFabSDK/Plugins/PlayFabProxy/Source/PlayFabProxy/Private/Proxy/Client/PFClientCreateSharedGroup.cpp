// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientCreateSharedGroup.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientCreateSharedGroup::UPFClientCreateSharedGroup(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FCreateSharedGroupDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientCreateSharedGroup* UPFClientCreateSharedGroup::CreateSharedGroup(class APlayerController* PlayerController, const FBPClientCreateSharedGroupRequest& InCreateSharedGroupRequest)
{
    UPFClientCreateSharedGroup* Proxy = NewObject<UPFClientCreateSharedGroup>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InCreateSharedGroupRequest;
    
    return Proxy;
}

void UPFClientCreateSharedGroup::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->CreateSharedGroup(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientCreateSharedGroup::OnSuccessCallback(const PlayFab::ClientModels::FCreateSharedGroupResult& Result)
{
    FBPClientCreateSharedGroupResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
