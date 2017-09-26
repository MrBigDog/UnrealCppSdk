// This is automatically generated by PlayFab SDKGenerator. DO NOT modify this manually!
#pragma once

#include "CoreMinimal.h"
#include "PlayFabProxyBaseModel.h"
#include "Core/PlayFabAdminAPI.h"
#include "Core/PlayFabAdminDataModels.h"
#include "Proxy/PlayFabAdminBPDataModels.h"
#include "PFAdminResetUsers.generated.h"

UCLASS(MinimalAPI)
class UPFAdminResetUsers : public UPlayFabProxyBase
{
    GENERATED_UCLASS_BODY()
public:

    UPROPERTY(BlueprintAssignable)
        FEmptyPlayFabDelegate OnSuccess; 

    // Resets all title-specific information about a particular account, including user data, virtual currency balances, inventory, purchase history, and statistics
    UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "PlayFab|Admin|Account Management")
        static UPFAdminResetUsers* ResetUsers(class APlayerController* PlayerController, const FBPAdminResetUsersRequest& InResetUsersRequest);

    // UOnlineBlueprintCallProxyBase interface
    virtual void Activate() override;
    // End of UOnlineBlueprintCallProxyBase interface

private:
    FBPAdminResetUsersRequest Request;
    PlayFab::UPlayFabAdminAPI::FResetUsersDelegate SuccessDelegate;

    void OnSuccessCallback(const PlayFab::AdminModels::FBlankResult& Result);
};
