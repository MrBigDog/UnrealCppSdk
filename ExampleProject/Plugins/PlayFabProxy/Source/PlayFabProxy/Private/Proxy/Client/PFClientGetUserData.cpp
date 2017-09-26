// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetUserData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetUserData::UPFClientGetUserData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetUserDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetUserData* UPFClientGetUserData::GetUserData(class APlayerController* PlayerController, const FBPClientGetUserDataRequest& InGetUserDataRequest)
{
    UPFClientGetUserData* Proxy = NewObject<UPFClientGetUserData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetUserDataRequest;
    
    return Proxy;
}

void UPFClientGetUserData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetUserData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetUserData::OnSuccessCallback(const PlayFab::ClientModels::FGetUserDataResult& Result)
{
    FBPClientGetUserDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
