// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminUpdateRandomResultTables.generated.h"

UCLASS(MinimalAPI)
class UPFAdminUpdateRandomResultTables : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Updates the random drop table configuration for the title
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Title-Wide Data Management")
        static UPFAdminUpdateRandomResultTables* UpdateRandomResultTables(class APlayerController* PlayerController, const FBPAdminUpdateRandomResultTablesRequest& InUpdateRandomResultTablesRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminUpdateRandomResultTablesRequest Request;
    PlayFab::UPlayFabAdminAPI::FUpdateRandomResultTablesDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FUpdateRandomResultTablesResult& Result);
};
