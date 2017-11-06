// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFClientGetCharacterData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFClientGetCharacterData::UPFClientGetCharacterData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabClientAPI::FGetCharacterDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFClientGetCharacterData* UPFClientGetCharacterData::GetCharacterData(class APlayerController* PlayerController, const FBPClientGetCharacterDataRequest& InGetCharacterDataRequest)
{
    UPFClientGetCharacterData* Proxy = NewObject<UPFClientGetCharacterData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetCharacterDataRequest;
    
    return Proxy;
}

void UPFClientGetCharacterData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabClientPtr ClientAPI = IPlayFabModuleInterface::Get().GetClientAPI();

    bool CallResult = false;

    if(ClientAPI.IsValid())
    {
        CallResult = ClientAPI->GetCharacterData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFClientGetCharacterData::OnSuccessCallback(const PlayFab::ClientModels::FGetCharacterDataResult& Result)
{
    FBPClientGetCharacterDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}