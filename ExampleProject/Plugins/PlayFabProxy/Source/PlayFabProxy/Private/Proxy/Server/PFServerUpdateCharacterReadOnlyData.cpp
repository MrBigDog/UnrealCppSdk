// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFServerUpdateCharacterReadOnlyData.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFServerUpdateCharacterReadOnlyData::UPFServerUpdateCharacterReadOnlyData(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabServerAPI::FUpdateCharacterReadOnlyDataDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFServerUpdateCharacterReadOnlyData* UPFServerUpdateCharacterReadOnlyData::UpdateCharacterReadOnlyData(class APlayerController* PlayerController, const FBPServerUpdateCharacterDataRequest& InUpdateCharacterDataRequest)
{
    UPFServerUpdateCharacterReadOnlyData* Proxy = NewObject<UPFServerUpdateCharacterReadOnlyData>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InUpdateCharacterDataRequest;
    
    return Proxy;
}

void UPFServerUpdateCharacterReadOnlyData::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabServerPtr ServerAPI = IPlayFabModuleInterface::Get().GetServerAPI();

    bool CallResult = false;

    if(ServerAPI.IsValid())
    {
        CallResult = ServerAPI->UpdateCharacterReadOnlyData(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFServerUpdateCharacterReadOnlyData::OnSuccessCallback(const PlayFab::ServerModels::FUpdateCharacterDataResult& Result)
{
    FBPServerUpdateCharacterDataResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}