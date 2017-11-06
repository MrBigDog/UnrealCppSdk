// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminSetStoreItems.generated.h"

UCLASS(MinimalAPI)
class UPFAdminSetStoreItems : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Sets all the items in one virtual store
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Title-Wide Data Management")
        static UPFAdminSetStoreItems* SetStoreItems(class APlayerController* PlayerController, const FBPAdminUpdateStoreItemsRequest& InUpdateStoreItemsRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminUpdateStoreItemsRequest Request;
    PlayFab::UPlayFabAdminAPI::FSetStoreItemsDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FUpdateStoreItemsResult& Result);
};