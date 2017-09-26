// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerGetUserAccountInfo.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerGetUserAccountInfo::UPFServerGetUserAccountInfo(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FGetUserAccountInfoDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerGetUserAccountInfo* UPFServerGetUserAccountInfo::GetUserAccountInfo(class APlayerController* PlayerController, const FBPServerGetUserAccountInfoRequest& InGetUserAccountInfoRequest)
{
    UPFServerGetUserAccountInfo* Proxy = NewObject<UPFServerGetUserAccountInfo>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetUserAccountInfoRequest;
    
    return Proxy;
}

void UPFServerGetUserAccountInfo::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->GetUserAccountInfo(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerGetUserAccountInfo::OnSuccessCallback(const PlayFab::ServerModels::FGetUserAccountInfoResult& Result)
{
    FBPServerGetUserAccountInfoResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
