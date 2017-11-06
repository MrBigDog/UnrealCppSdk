// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetDataReport.generated.h"

UCLASS(MinimalAPI)
class UPFAdminGetDataReport : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminGetDataReportResultDelegate OnSuccess;

    // Retrieves a download URL for the requested report
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Player Data Management")
        static UPFAdminGetDataReport* GetDataReport(class APlayerController* PlayerController, const FBPAdminGetDataReportRequest& InGetDataReportRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminGetDataReportRequest Request;
    PlayFab::UPlayFabAdminAPI::FGetDataReportDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FGetDataReportResult& Result);
};