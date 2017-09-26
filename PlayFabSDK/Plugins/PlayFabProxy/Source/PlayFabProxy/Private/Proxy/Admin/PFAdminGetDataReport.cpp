// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!

#include "PFAdminGetDataReport.h"
#include "PlayFabProxy.h"
#include "PlayFab.h"

UPFAdminGetDataReport::UPFAdminGetDataReport(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , SuccessDelegate(PlayFab::UPlayFabAdminAPI::FGetDataReportDelegate::CreateUObject(this, &ThisClass::OnSuccessCallback))
{
}

UPFAdminGetDataReport* UPFAdminGetDataReport::GetDataReport(class APlayerController* PlayerController, const FBPAdminGetDataReportRequest& InGetDataReportRequest)
{
    UPFAdminGetDataReport* Proxy = NewObject<UPFAdminGetDataReport>();
    Proxy->PlayerControllerWeakPtr = PlayerController;
    Proxy->Request = InGetDataReportRequest;
    
    return Proxy;
}

void UPFAdminGetDataReport::Activate()
{
    // grab the module, so we can get a valid pointer to the client API
    PlayFabAdminPtr AdminAPI = IPlayFabModuleInterface::Get().GetAdminAPI();

    bool CallResult = false;

    if(AdminAPI.IsValid())
    {
        CallResult = AdminAPI->GetDataReport(Request.Data, SuccessDelegate, ErrorDelegate);
    }

    if(CallResult == false)
    {
        OnFailure.Broadcast();
    }
}

void UPFAdminGetDataReport::OnSuccessCallback(const PlayFab::AdminModels::FGetDataReportResult& Result)
{
    FBPAdminGetDataReportResult BPResult;
     BPResult.Data = Result;
     OnSuccess.Broadcast(BPResult);
}
