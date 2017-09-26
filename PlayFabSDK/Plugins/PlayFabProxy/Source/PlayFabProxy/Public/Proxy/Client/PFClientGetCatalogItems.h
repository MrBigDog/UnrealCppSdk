// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientGetCatalogItems.generated.h"

UCLASS(MinimalAPI)
class UPFClientGetCatalogItems : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPClientGetCatalogItemsResultDelegate OnSuccess;

    // Retrieves the specified version of the title's catalog of virtual goods, including all defined properties
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Title-Wide Data Management")
        static UPFClientGetCatalogItems* GetCatalogItems(class APlayerController* PlayerController, const FBPClientGetCatalogItemsRequest& InGetCatalogItemsRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientGetCatalogItemsRequest Request;
    PlayFab::UPlayFabClientAPI::FGetCatalogItemsDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FGetCatalogItemsResult& Result);
};
