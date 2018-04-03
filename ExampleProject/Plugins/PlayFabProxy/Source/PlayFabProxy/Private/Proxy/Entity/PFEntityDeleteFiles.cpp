// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFEntityDeleteFiles.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFEntityDeleteFiles::UPFEntityDeleteFiles(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabEntityAPI::FDeleteFilesDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFEntityDeleteFiles* UPFEntityDeleteFiles::DeleteFiles(class APlayerController* PlayerController, const FBPEntityDeleteFilesRequest& InDeleteFilesRequest)
{
    UPFEntityDeleteFiles* Proxy = NewObject<UPFEntityDeleteFiles>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InDeleteFilesRequest;
    
    return Proxy;
}

void UPFEntityDeleteFiles::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabEntityPtr EntityAPI = IPlayFabModuleInterface::Get().GetEntityAPI();

    bool CallResult = false;

    if (EntityAPI.IsValid())
    {
        CallResult = EntityAPI->DeleteFiles(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if (CallResult == false)
        OnFailure.Broadcast();
}

void UPFEntityDeleteFiles::OnSuccessCallback(const PlayFab::EntityModels::FDeleteFilesResponse& Result)
{
    FBPEntityDeleteFilesResponse BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}