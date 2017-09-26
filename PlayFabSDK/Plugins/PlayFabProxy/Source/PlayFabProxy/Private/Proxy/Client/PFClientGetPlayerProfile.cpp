// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetPlayerProfile.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetPlayerProfile::UPFClientGetPlayerProfile(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetPlayerProfileDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetPlayerProfile* UPFClientGetPlayerProfile::GetPlayerProfile(class APlayerController* PlayerController, const FBPClientGetPlayerProfileRequest& InGetPlayerProfileRequest)
{
    UPFClientGetPlayerProfile* Proxy = NewObject<UPFClientGetPlayerProfile>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetPlayerProfileRequest;
    
    return Proxy;
}

void UPFClientGetPlayerProfile::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetPlayerProfile(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetPlayerProfile::OnSuccessCallback(const PlayFab::ClientModels::FGetPlayerProfileResult& Result)
{
    FBPClientGetPlayerProfileResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
