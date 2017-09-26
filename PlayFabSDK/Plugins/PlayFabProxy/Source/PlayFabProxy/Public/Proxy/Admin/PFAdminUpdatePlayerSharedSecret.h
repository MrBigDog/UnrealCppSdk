// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminUpdatePlayerSharedSecret.generated.h"

UCLASS(MinimalAPI)
class UPFAdminUpdatePlayerSharedSecret : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Updates a existing Player Shared Secret Key. It may take up to 5 minutes for this update to become generally available after this API returns.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Authentication")
        static UPFAdminUpdatePlayerSharedSecret* UpdatePlayerSharedSecret(class APlayerController* PlayerController, const FBPAdminUpdatePlayerSharedSecretRequest& InUpdatePlayerSharedSecretRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminUpdatePlayerSharedSecretRequest Request;
    PlayFab::UPlayFabAdminAPI::FUpdatePlayerSharedSecretDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FUpdatePlayerSharedSecretResult& Result);
};
