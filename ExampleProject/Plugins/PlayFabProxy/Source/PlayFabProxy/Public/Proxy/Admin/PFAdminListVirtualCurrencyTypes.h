// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminListVirtualCurrencyTypes.generated.h"

UCLASS(MinimalAPI)
class UPFAdminListVirtualCurrencyTypes : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminListVirtualCurrencyTypesResultDelegate OnSuccess;

    // Retuns the list of all defined virtual currencies for the title
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Title-Wide Data Management")
        static UPFAdminListVirtualCurrencyTypes* ListVirtualCurrencyTypes(class APlayerController* PlayerController);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    
    PlayFab::UPlayFabAdminAPI::FListVirtualCurrencyTypesDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FListVirtualCurrencyTypesResult& Result);
};
