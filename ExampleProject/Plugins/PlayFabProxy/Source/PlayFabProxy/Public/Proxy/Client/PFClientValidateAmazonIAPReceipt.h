// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabClientAPI.h"
#include "Core/PlayFabClientDataModels.h"
#include "Proxy/PlayFabClientBPDataModels.h"
#include "PFClientValidateAmazonIAPReceipt.generated.h"

UCLASS(MinimalAPI)
class UPFClientValidateAmazonIAPReceipt : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Validates with Amazon that the receipt for an Amazon App Store in-app purchase is valid and that it matches the purchased catalog item
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Client|Platform Specific Methods")
        static UPFClientValidateAmazonIAPReceipt* ValidateAmazonIAPReceipt(class APlayerController* PlayerController, const FBPClientValidateAmazonReceiptRequest& InValidateAmazonReceiptRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPClientValidateAmazonReceiptRequest Request;
    PlayFab::UPlayFabClientAPI::FValidateAmazonIAPReceiptDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::ClientModels::FValidateAmazonReceiptResult& Result);
};
