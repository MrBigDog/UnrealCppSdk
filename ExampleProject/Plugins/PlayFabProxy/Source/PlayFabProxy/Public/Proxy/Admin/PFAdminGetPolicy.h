// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminGetPolicy.generated.h"

UCLASS(MinimalAPI)
class UPFAdminGetPolicy : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FBPAdminGetPolicyResponseDelegate OnSuccess;

    // Gets the requested policy.
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Authentication")
        static UPFAdminGetPolicy* GetPolicy(class APlayerController* PlayerController, const FBPAdminGetPolicyRequest& InGetPolicyRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminGetPolicyRequest Request;
    PlayFab::UPlayFabAdminAPI::FGetPolicyDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FGetPolicyResponse& Result);
};
